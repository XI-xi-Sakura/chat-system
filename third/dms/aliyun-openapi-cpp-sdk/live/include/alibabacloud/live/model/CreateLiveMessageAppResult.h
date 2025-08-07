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

#ifndef ALIBABACLOUD_LIVE_MODEL_CREATELIVEMESSAGEAPPRESULT_H_
#define ALIBABACLOUD_LIVE_MODEL_CREATELIVEMESSAGEAPPRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/live/LiveExport.h>

namespace AlibabaCloud
{
	namespace Live
	{
		namespace Model
		{
			class ALIBABACLOUD_LIVE_EXPORT CreateLiveMessageAppResult : public ServiceResult
			{
			public:


				CreateLiveMessageAppResult();
				explicit CreateLiveMessageAppResult(const std::string &payload);
				~CreateLiveMessageAppResult();
				std::string getDataCenter()const;
				std::string getAppId()const;
				std::string getAppKey()const;
				std::string getAppSign()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string dataCenter_;
				std::string appId_;
				std::string appKey_;
				std::string appSign_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_LIVE_MODEL_CREATELIVEMESSAGEAPPRESULT_H_