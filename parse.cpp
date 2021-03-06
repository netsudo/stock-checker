#include "parse.h"

const std::string Parser::user_agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36";
const std::string Parser::header_accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8";

void Parser::setHeaders() {
	request.setOpt(curlpp::options::Url(url));
	headers.push_back(header_accept);
	headers.push_back(user_agent);
}

void Parser::setRequest() {
	request.setOpt(new curlpp::options::HttpHeader(headers));
	request.setOpt(new curlpp::options::FollowLocation(true));
}

std::ostringstream Parser::performRequest() {
	/* Used in a couple functions, need it because default behavior
	 * is to output HTML to console and has to be overridden */
	std::ostringstream responseStream;
	curlpp::options::WriteStream streamWriter(&responseStream);
	request.setOpt(streamWriter);
	request.perform();

	return responseStream;
}

std::string Parser::responseStream() { 
	std::string re = performRequest().str();

	return re;
}

int Parser::requestStatusCode() { 
	return curlpp::infos::ResponseCode::get(request);
}

bool Parser::validURL() {
	setRequest();
	setHeaders();

	try {
		performRequest();
	}

	catch (curlpp::LibcurlRuntimeError) {
		return false;
	}

	if ( requestStatusCode() == 200 ) {
		return true;
	}

	return false;
}

bool Parser::inStock() { 
	setRequest();
	setHeaders();

	xmlDocPtr doc = htmlReadDoc((xmlChar*)responseStream().c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

	// Encapsulate raw libxml document in a libxml++ wrapper
	xmlNodePtr r = xmlDocGetRootElement(doc);

	xmlpp::Element* root = new xmlpp::Element(r);

	std::string xpath = "//*[@id=\"productDetailsAddToCartForm\"]/div/div[13]/div";
	auto elements = root->find(xpath);

	if (requestStatusCode() == 200) {
		if (elements.size() != 0) {
			return true;
		}
	}

	return false;
}
