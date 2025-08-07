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

#ifndef ALIBABACLOUD_SWAS_OPEN_MODEL_CREATEKEYPAIRRESULT_H_
#define ALIBABACLOUD_SWAS_OPEN_MODEL_CREATEKEYPAIRRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/swas-open/SWAS_OPENExport.h>

namespace AlibabaCloud
{
	namespace SWAS_OPEN
	{
		namespace Model
		{
			class ALIBABACLOUD_SWAS_OPEN_EXPORT CreateKeyPairResult : public ServiceResult
			{
			public:


				CreateKeyPairResult();
				explicit CreateKeyPairResult(const std::string &payload);
				~CreateKeyPairResult();
				std::string getKeyPairName()const;
				std::string getPrivateKeyBody()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string keyPairName_;
				std::string privateKeyBody_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_SWAS_OPEN_MODEL_CREATEKEYPAIRRESULT_H_