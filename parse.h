#ifndef PARSE_H
#define PARSE_H

#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml++/libxml++.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <iostream>
#include <string>

class Parser {
	public:
		std::string url;

		bool validURL();

		bool inStock();

	private:
		static const std::string user_agent;

		static const std::string header_accept;

		curlpp::Easy request;

		std::list<std::string> headers;

		void setHeaders();

		void setRequest();

		std::string responseStream();

		int requestStatusCode();

		std::ostringstream performRequest();

};


#endif
