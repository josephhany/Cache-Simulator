#include <DirectMap.h>
#include <Utils.h>
#include <fstream>
//~/work/cache_sim/bin/pin-3.11-97998-g7ecce2dac-gcc-linux/source/tools

DirectMap::DirectMap (uint16_t p_cache_line_size , uint16_t p_cache_size, bool _wb)
{
    //Write your code here
	cache_line_size = p_cache_line_size;
	cache_size = p_cache_size;
	Utils utils;
	cs_bits = utils.get_first_one_pos<uint64_t>(cache_size)-1;
	ls_bits = utils.get_first_one_pos<uint64_t>(cache_line_size)-1;
	for ( uint16_t i = 0 ; i < cache_size ; i++){
        	cache.insert(std::pair<uint16_t,CacheLine *>(i,new CacheLine(_wb)));
	}
}
void DirectMap::access (uint64_t full_address,char mode)
{
    //Write your code here
	Utils utils;
	uint64_t tag = utils.extract_bits<uint64_t>(full_address,64 - (cs_bits+ls_bits),cs_bits+ls_bits);
	cache[utils.extract_bits<uint64_t>(full_address,cs_bits,ls_bits)]->access(tag,mode);
	

}
void DirectMap::printStats (unsigned int crc,unsigned int cwc ,unsigned int mrc ,unsigned int mwc,FILE * f)
{
   //Write your code here
	uint64_t TotalHits=0;
	uint64_t TotalMisses=0;
	uint64_t TotalCacheReads=0;
	uint64_t TotalCacheWrites=0;
	uint64_t TotalMEMReads=0;
	uint64_t TotalMEMWrites=0;

for ( uint16_t i = 0 ; i < cache_size ; i++){
	
	CacheLine * cache_cpy = cache.find(i)->second;
	TotalHits+=cache_cpy->getHits();	
	TotalMisses+=cache_cpy->getMisses();
	TotalCacheReads+=cache_cpy->getCacheReads();
	TotalCacheWrites+=cache_cpy->getCacheWrites();
	TotalMEMReads+=cache_cpy->getMEMReads();
	TotalMEMWrites+=cache_cpy->getMEMWrites();
}

	fprintf(f,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",TotalMisses,TotalHits,((TotalMisses/(TotalHits+TotalMisses))*100),TotalCacheReads,TotalCacheWrites,TotalCacheReads+TotalCacheWrites,TotalMEMReads,TotalMEMWrites,crc*TotalCacheReads,cwc*TotalCacheWrites,crc*TotalCacheReads+cwc*TotalCacheWrites,mrc*TotalMEMReads,mwc*TotalMEMWrites,mrc*TotalMEMReads+mwc*TotalMEMWrites);
	
	printf ("Done...\n");
	//printf ("%d %d %d %d %d %d %d\n",TotalMisses,TotalHits,TotalCacheReads,TotalCacheWrites,TotalCacheReads+TotalCacheWrites,TotalMEMReads,TotalMEMWrites);

	//printf ("Total Misses: %d\n",TotalMisses);
	//printf ("Total Hits: %d\n",TotalHits);
	//printf ("Memory Read Access Attempts: %d\n",TotalCacheReads);
	//printf ("Memory Write Access Attempts: %d\n",TotalCacheWrites);
	//printf ("Total Memory Access Attempts: %d\n",TotalCacheReads+TotalCacheWrites);
	//printf ("Memory Read Access: %d\n",TotalMEMReads);
	//printf ("Memory Write Access: %d\n",TotalMEMWrites);


	//printf ("Total # of Cycles for Cache Reads: %d\n",crc*TotalCacheReads);
	//printf ("Total # of Cycles for Cache Writes: %d\n",cwc*TotalCacheWrites);
	//printf ("Total # of Cycles for Cache access: %d\n",crc*TotalCacheReads+cwc*TotalCacheWrites);

	//printf ("Total # of Cycles for Memory Reads: %d\n",mrc*TotalMEMReads);
	//printf ("Total # of Cycles for Memory Writes: %d\n",mwc*TotalMEMWrites);
	//printf ("Total # of Cycles for Memory access: %d\n",mrc*TotalMEMReads+mwc*TotalMEMWrites);
}

DirectMap::~DirectMap()
{
    for ( uint16_t i = 0 ; i < cache_size ; i++)
        delete (cache[i]);
}
