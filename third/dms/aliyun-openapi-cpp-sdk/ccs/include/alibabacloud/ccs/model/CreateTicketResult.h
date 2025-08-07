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

#ifndef ALIBABACLOUD_CCS_MODEL_CREATETICKETRESULT_H_
#define ALIBABACLOUD_CCS_MODEL_CREATETICKETRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/ccs/CcsExport.h>

namespace AlibabaCloud
{
	namespace Ccs
	{
		namespace Model
		{
			class ALIBABACLOUD_CCS_EXPORT CreateTicketResult : public ServiceResult
			{
			public:


				CreateTicketResult();
				explicit CreateTicketResult(const std::string &payload);
				~CreateTicketResult();
				std::string getId()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string id_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_CCS_MODEL_CREATETICKETRESULT_H_