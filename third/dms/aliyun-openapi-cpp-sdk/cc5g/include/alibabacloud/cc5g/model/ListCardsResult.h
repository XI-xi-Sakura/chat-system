/*
 * Copyright 2009-2017 Alibaba Cloud All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ALIBABACLOUD_CC5G_MODEL_LISTCARDSRESULT_H_
#define ALIBABACLOUD_CC5G_MODEL_LISTCARDSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/cc5g/CC5GExport.h>

namespace AlibabaCloud
{
	namespace CC5G
	{
		namespace Model
		{
			class ALIBABACLOUD_CC5G_EXPORT ListCardsResult : public ServiceResult
			{
			public:
				struct Card
				{
					std::string status;
					std::string usageDataTotal;
					std::string description;
					long usageDataMonth;
					std::string iSP;
					std::string imei;
					std::string orderId;
					std::string businessStatus;
					bool lock;
					std::string name;
					std::string msisdn;
					std::string activatedTime;
					std::string iccid;
					std::string imsi;
					std::string ipAddress;
					std::string spec;
					std::string netType;
					std::string aPN;
				};


				ListCardsResult();
				explicit ListCardsResult(const std::string &payload);
				~ListCardsResult();
				std::string getTotalCount()const;
				std::string getNextToken()const;
				std::string getMaxResults()const;
				std::vector<Card> getCards()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string totalCount_;
				std::string nextToken_;
				std::string maxResults_;
				std::vector<Card> cards_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_CC5G_MODEL_LISTCARDSRESULT_H_