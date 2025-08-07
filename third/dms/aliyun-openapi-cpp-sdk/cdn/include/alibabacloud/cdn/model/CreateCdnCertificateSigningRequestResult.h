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

#ifndef ALIBABACLOUD_CDN_MODEL_CREATECDNCERTIFICATESIGNINGREQUESTRESULT_H_
#define ALIBABACLOUD_CDN_MODEL_CREATECDNCERTIFICATESIGNINGREQUESTRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/cdn/CdnExport.h>

namespace AlibabaCloud
{
	namespace Cdn
	{
		namespace Model
		{
			class ALIBABACLOUD_CDN_EXPORT CreateCdnCertificateSigningRequestResult : public ServiceResult
			{
			public:


				CreateCdnCertificateSigningRequestResult();
				explicit CreateCdnCertificateSigningRequestResult(const std::string &payload);
				~CreateCdnCertificateSigningRequestResult();
				std::string getPubMd5()const;
				std::string getCsr()const;
				std::string getCommonName()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string pubMd5_;
				std::string csr_;
				std::string commonName_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_CDN_MODEL_CREATECDNCERTIFICATESIGNINGREQUESTRESULT_H_