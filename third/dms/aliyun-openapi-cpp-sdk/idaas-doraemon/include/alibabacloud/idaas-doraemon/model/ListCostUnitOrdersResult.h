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

#ifndef ALIBABACLOUD_IDAAS_DORAEMON_MODEL_LISTCOSTUNITORDERSRESULT_H_
#define ALIBABACLOUD_IDAAS_DORAEMON_MODEL_LISTCOSTUNITORDERSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/idaas-doraemon/Idaas_doraemonExport.h>

namespace AlibabaCloud
{
	namespace Idaas_doraemon
	{
		namespace Model
		{
			class ALIBABACLOUD_IDAAS_DORAEMON_EXPORT ListCostUnitOrdersResult : public ServiceResult
			{
			public:
				struct Item
				{
					long refundTime;
					std::string orderStatus;
					std::string aliOrderInstanceId;
					std::string aliOrderCode;
					long totalCostUnit;
					long createTime;
					long expiredTime;
					long usedCostUnit;
					bool exhausted;
				};


				ListCostUnitOrdersResult();
				explicit ListCostUnitOrdersResult(const std::string &payload);
				~ListCostUnitOrdersResult();
				long getPageSize()const;
				long getTotalElements()const;
				std::vector<Item> getItems()const;
				long getTotalPages()const;

			protected:
				void parse(const std::string &payload);
			private:
				long pageSize_;
				long totalElements_;
				std::vector<Item> items_;
				long totalPages_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_IDAAS_DORAEMON_MODEL_LISTCOSTUNITORDERSRESULT_H_