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

#ifndef ALIBABACLOUD_DOMAIN_MODEL_QUERYOPERATIONAUDITINFODETAILREQUEST_H_
#define ALIBABACLOUD_DOMAIN_MODEL_QUERYOPERATIONAUDITINFODETAILREQUEST_H_

#include <alibabacloud/domain/DomainExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Domain {
namespace Model {
class ALIBABACLOUD_DOMAIN_EXPORT QueryOperationAuditInfoDetailRequest : public RpcServiceRequest {
public:
	QueryOperationAuditInfoDetailRequest();
	~QueryOperationAuditInfoDetailRequest();
	long getAuditRecordId() const;
	void setAuditRecordId(long auditRecordId);
	std::string getLang() const;
	void setLang(const std::string &lang);

private:
	long auditRecordId_;
	std::string lang_;
};
} // namespace Model
} // namespace Domain
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_DOMAIN_MODEL_QUERYOPERATIONAUDITINFODETAILREQUEST_H_
