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

#ifndef ALIBABACLOUD_WORKORDER_MODEL_LISTPRODUCTSRESULT_H_
#define ALIBABACLOUD_WORKORDER_MODEL_LISTPRODUCTSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/workorder/WorkorderExport.h>

namespace AlibabaCloud
{
	namespace Workorder
	{
		namespace Model
		{
			class ALIBABACLOUD_WORKORDER_EXPORT ListProductsResult : public ServiceResult
			{
			public:
				struct DataItem
				{
					struct ProductListItem
					{
						std::string productName;
						long productId;
					};
					std::vector<DataItem::ProductListItem> productList;
					long directoryId;
					std::string directoryName;
				};


				ListProductsResult();
				explicit ListProductsResult(const std::string &payload);
				~ListProductsResult();
				std::string getMessage()const;
				std::vector<DataItem> getData()const;
				int getCode()const;
				bool getSuccess()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string message_;
				std::vector<DataItem> data_;
				int code_;
				bool success_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_WORKORDER_MODEL_LISTPRODUCTSRESULT_H_