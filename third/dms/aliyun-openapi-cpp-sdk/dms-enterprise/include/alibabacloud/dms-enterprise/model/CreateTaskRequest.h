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

#ifndef ALIBABACLOUD_DMS_ENTERPRISE_MODEL_CREATETASKREQUEST_H_
#define ALIBABACLOUD_DMS_ENTERPRISE_MODEL_CREATETASKREQUEST_H_

#include <alibabacloud/dms-enterprise/Dms_enterpriseExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Dms_enterprise {
namespace Model {
class ALIBABACLOUD_DMS_ENTERPRISE_EXPORT CreateTaskRequest : public RpcServiceRequest {
public:
	CreateTaskRequest();
	~CreateTaskRequest();
	std::string getNodeType() const;
	void setNodeType(const std::string &nodeType);
	long getDagId() const;
	void setDagId(long dagId);
	long getTid() const;
	void setTid(long tid);
	std::string getNodeContent() const;
	void setNodeContent(const std::string &nodeContent);
	std::string getNodeOutput() const;
	void setNodeOutput(const std::string &nodeOutput);
	std::string getGraphParam() const;
	void setGraphParam(const std::string &graphParam);
	std::string getTimeVariables() const;
	void setTimeVariables(const std::string &timeVariables);
	std::string getNodeName() const;
	void setNodeName(const std::string &nodeName);

private:
	std::string nodeType_;
	long dagId_;
	long tid_;
	std::string nodeContent_;
	std::string nodeOutput_;
	std::string graphParam_;
	std::string timeVariables_;
	std::string nodeName_;
};
} // namespace Model
} // namespace Dms_enterprise
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_DMS_ENTERPRISE_MODEL_CREATETASKREQUEST_H_
