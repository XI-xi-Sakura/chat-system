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

#ifndef ALIBABACLOUD_CAS_MODEL_ENCRYPTREQUEST_H_
#define ALIBABACLOUD_CAS_MODEL_ENCRYPTREQUEST_H_

#include <alibabacloud/cas/CasExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Cas {
namespace Model {
class ALIBABACLOUD_CAS_EXPORT EncryptRequest : public RpcServiceRequest {
public:
	EncryptRequest();
	~EncryptRequest();
	std::string getMessageType() const;
	void setMessageType(const std::string &messageType);
	std::string getPlaintext() const;
	void setPlaintext(const std::string &plaintext);
	std::string getSourceIp() const;
	void setSourceIp(const std::string &sourceIp);
	std::string getCertIdentifier() const;
	void setCertIdentifier(const std::string &certIdentifier);
	std::string getAlgorithm() const;
	void setAlgorithm(const std::string &algorithm);

private:
	std::string messageType_;
	std::string plaintext_;
	std::string sourceIp_;
	std::string certIdentifier_;
	std::string algorithm_;
};
} // namespace Model
} // namespace Cas
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_CAS_MODEL_ENCRYPTREQUEST_H_
