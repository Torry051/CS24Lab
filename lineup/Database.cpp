#include "Database.h"

// Database Member Functions

Database *Database::create()
{
	return new Database();
}
Database::Database()
{
	// this->data.reserve(400000);
}

void Database::insert(const Report *report)
{
	if (this->data.count(report->id) == 0)
	{
		// this->data[report->id] = report;
		this->data.insert({report->id, report});
	}
	else
	{	

		throw DuplicateReport(report->id);
	}
}

Database::~Database()
{
	for(auto curr = data.begin(); curr != data.end(); curr++ ){
		delete curr->second;
	}
}

std::vector<const Report *> Database::search(float age, float height, float weight) const
{
	std::vector<const Report *> result;
	for (auto pair = this->data.begin(); pair != this->data.end(); pair++)
	{
		if (age < pair->second->age.min || age > pair->second->age.max)
		{
			continue;
		}
		if (height < pair->second->height.min || height > pair->second->height.max)
		{
			continue;
		}
		if (weight < pair->second->weight.min || weight > pair->second->weight.max)
		{
			continue;
		}
		result.push_back(pair->second);
	}
	return result;
}

void Database::remove(unsigned int id)
{
	if (this->data.count(id) == 0)
	{
		throw NoSuchReport(id);
	}
	else
	{
		// delete data[id];
		this->data.erase(id);
	}
}
