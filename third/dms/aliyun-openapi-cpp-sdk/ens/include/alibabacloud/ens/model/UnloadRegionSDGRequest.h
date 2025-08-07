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

#ifndef ALIBABACLOUD_ENS_MODEL_UNLOADREGIONSDGREQUEST_H_
#define ALIBABACLOUD_ENS_MODEL_UNLOADREGIONSDGREQUEST_H_

#include <alibabacloud/ens/EnsExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ens {
namespace Model {
class ALIBABACLOUD_ENS_EXPORT UnloadRegionSDGRequest : public RpcServiceRequest {
public:
	UnloadRegionSDGRequest();
	~UnloadRegionSDGRequest();
	std::vector<std::string> getDestinationRegionIds() const;
	void setDestinationRegionIds(const std::vector<std::string> &destinationRegionIds);
	std::string getSDGId() const;
	void setSDGId(const std::string &sDGId);
	std::vector<std::string> getNamespaces() const;
	void setNamespaces(const std::vector<std::string> &namespaces);

private:
	std::vector<std::string> destinationRegionIds_;
	std::string sDGId_;
	std::vector<std::string> namespaces_;
};
} // namespace Model
} // namespace Ens
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ENS_MODEL_UNLOADREGIONSDGREQUEST_H_
