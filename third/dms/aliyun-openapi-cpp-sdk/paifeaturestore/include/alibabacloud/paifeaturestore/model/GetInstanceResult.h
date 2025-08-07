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

#ifndef ALIBABACLOUD_PAIFEATURESTORE_MODEL_GETINSTANCERESULT_H_
#define ALIBABACLOUD_PAIFEATURESTORE_MODEL_GETINSTANCERESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/paifeaturestore/PaiFeatureStoreExport.h>

namespace AlibabaCloud
{
	namespace PaiFeatureStore
	{
		namespace Model
		{
			class ALIBABACLOUD_PAIFEATURESTORE_EXPORT GetInstanceResult : public ServiceResult
			{
			public:
				struct FeatureDBInstanceInfo
				{
					std::string status;
				};
				struct FeatureDBInfo
				{
					std::string status;
				};


				GetInstanceResult();
				explicit GetInstanceResult(const std::string &payload);
				~GetInstanceResult();
				std::string getStatus()const;
				double getProgress()const;
				std::string getType()const;
				std::string getMessage()const;
				FeatureDBInstanceInfo getFeatureDBInstanceInfo()const;
				FeatureDBInfo getFeatureDBInfo()const;
				std::string getRegionId()const;
				std::string getGmtCreateTime()const;
				std::string getGmtModifiedTime()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string status_;
				double progress_;
				std::string type_;
				std::string message_;
				FeatureDBInstanceInfo featureDBInstanceInfo_;
				FeatureDBInfo featureDBInfo_;
				std::string regionId_;
				std::string gmtCreateTime_;
				std::string gmtModifiedTime_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_PAIFEATURESTORE_MODEL_GETINSTANCERESULT_H_