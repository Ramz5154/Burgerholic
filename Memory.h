//#ifndef MEMORY_H
//#define MEMORY_H
//
//#include <iostream>
//#include <memory>
//#include <atomic>
// 
// 
// UNVOMMENT TO SEE ALL MEMORY LEAKS 
// 
//
//// Thread-safe counters for memory tracking
//namespace MemoryMonitor {
//     std::atomic<std::size_t> numAllocations{ 0 };
//     std::atomic<std::size_t> numDeallocations{ 0 };
//     std::atomic<std::size_t> totalAllocatedBytes{ 0 };
//     std::atomic<std::size_t> totalDeallocatedBytes{ 0 };
//}
//
//// Overloaded `new` operator
//void* operator new(std::size_t size) {
//    MemoryMonitor::numAllocations++;
//    MemoryMonitor::totalAllocatedBytes += size;
//    std::cout << "[MemoryMonitor] Allocated: " << size << " bytes\n";
//    return std::malloc(size);
//}
//
//// Overloaded `delete` operator
//void operator delete(void* ptr, std::size_t size) noexcept {
//    MemoryMonitor::numDeallocations++;
//    MemoryMonitor::totalDeallocatedBytes += size;
//    std::cout << "[MemoryMonitor] Deallocated: " << size << " bytes\n";
//    std::free(ptr);
//}
//
//// Overloaded `new[]` operator for arrays
//void* operator new[](std::size_t size) {
//    MemoryMonitor::numAllocations++;
//    MemoryMonitor::totalAllocatedBytes += size;
//    std::cout << "[MemoryMonitor] Allocated array: " << size << " bytes\n";
//    return std::malloc(size);
//}
//
//// Overloaded `delete[]` operator for arrays
//void operator delete[](void* ptr) noexcept {
//    MemoryMonitor::numDeallocations++;
//    std::cout << "[MemoryMonitor] Deallocated array\n";
//    std::free(ptr);
//}
//
//// Summary function
//inline void PrintSummary() {
//    std::cout << "\n[MemoryMonitor] === Summary ===\n";
//    std::cout << "Allocations: " << MemoryMonitor::numAllocations.load() << "\n";
//    std::cout << "Deallocations: " << MemoryMonitor::numDeallocations.load() << "\n";
//    std::cout << "Total Allocated Bytes: " << MemoryMonitor::totalAllocatedBytes.load() << "\n";
//    std::cout << "Total Deallocated Bytes: " << MemoryMonitor::totalDeallocatedBytes.load() << "\n";
//
//    if (MemoryMonitor::totalAllocatedBytes > MemoryMonitor::totalDeallocatedBytes) {
//        std::cout << "Memory Leak Detected: "
//            << (MemoryMonitor::totalAllocatedBytes - MemoryMonitor::totalDeallocatedBytes)
//            << " bytes\n";
//    }
//    else {
//        std::cout << "No memory leaks detected.\n";
//    }
//}
//
//#endif // MEMORYMANAGER_H
