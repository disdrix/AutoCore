// =============================================================================
// gfxUIWindow_CompleteDtor  (aa_00759de0)
// -----------------------------------------------------------------------------
// Address:   0x00759de0  (autoassault.exe, image base 0x400000)
// Body:      0x00759de0–0x0075a143 inclusive (868 B / 0x364)
// Wave:      WQ9L-F OWN-ONLY dual 2026-08-05
// System:    gfxUIWindow / MSVC complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + multi-span read_memory + RTTI COL. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for gfxUIWindow (RTTI .?AVgfxUIWindow@@).
//   Installs primary vtbl PTR_FUN_00a9f304, tears tree shells / vectors /
//   refcounted slots, asserts if children remain attached, finishes nested
//   subobject at +0x30, and returns without freeing this.
//   Super-base of CNDUIWindow_CompleteDtor (0x007b5be0).
//
// ABI:
//   ECX = this. SEH LAB_009b3156. Bare RET (C3 @ 0x0075a0f4). void.
//
// STRINGS:
//   "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"
//   "Window deleted with children still attached!"
//   "c:\\VOGCRASH.txt" / errReport EH_Abort path (assert==3)
//
// PEERS:
//   Scalar: FUN_004401b0 (vtbl[0] of PTR_FUN_00a9f304)
//   Derived: CNDUIWindow_CompleteDtor 0x007b5be0 chains into this
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <csignal>

extern uint32_t PTR_FUN_00a9f304; // gfxUIWindow primary vtbl
extern uint32_t PTR_FUN_00a9db18; // nested mid-dtor vtbl written at +0x30

extern "C" void __fastcall FUN_00440c90(void* tree, void* node);
extern "C" void __fastcall FUN_00440ab0(void* tree, void* node);
extern "C" void __fastcall FUN_00440d20(void* tree, void* node);
extern "C" void __fastcall FUN_00441960(void* out, void* first, void* last);
extern "C" void __fastcall FUN_00441720(void* out, void* first, void* last);
extern "C" void __fastcall FUN_00988710(void* obj);
extern "C" void __cdecl FUN_00756be0(void* self);
extern "C" int  __cdecl FUN_0076d1b0(const char* file, int line, const char* msg);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __stdcall ExitProcess(unsigned code);

// Tree shell layout used repeatedly: head* @ +4, size @ +8 (head self-linked).
struct TreeShell {
  uint32_t pad0;
  uint32_t* head;
  uint32_t size;
};

static void clear_tree_shell_head_selflink(TreeShell* shell)
{
  // After erase-all helper: head->parent = head; size = 0; head L/R self.
  uint32_t* head = shell->head;
  head[1] = reinterpret_cast<uint32_t>(head); // parent
  shell->size = 0;
  head[0] = reinterpret_cast<uint32_t>(head); // left
  head[2] = reinterpret_cast<uint32_t>(head); // right
}

static void free_vector_triple(uint32_t* begin_slot)
{
  void* p = reinterpret_cast<void*>(begin_slot[0]);
  if (p) {
    operator_delete(p);
  }
  begin_slot[0] = 0;
  begin_slot[1] = 0;
  begin_slot[2] = 0;
}

// Complete dtor only — does not free self.
extern "C" void __fastcall gfxUIWindow_CompleteDtor(uint32_t* self)
{
  // SEH: LAB_009b3156; ESI=this; EBX=0; EH state starts at 7
  auto* b = reinterpret_cast<uint8_t*>(self);

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9f304);

  // --- shell @ +0x10 ---
  TreeShell* shell10 = reinterpret_cast<TreeShell*>(b + 0x10);
  FUN_00440c90(shell10, reinterpret_cast<void*>(shell10->head[1]));
  clear_tree_shell_head_selflink(shell10);

  // --- refcounted iface @ +0x34 ---
  if (int* rc = reinterpret_cast<int*>(self[0xD])) {
    rc[1] -= 1;
    if (rc[1] == 0) {
      void** vtbl = *reinterpret_cast<void***>(rc);
      reinterpret_cast<void(__thiscall*)(void*)>(vtbl[2])(rc); // +0x8
    }
    self[0xD] = 0;
  }

  // --- vector @ +0x5c ---
  free_vector_triple(self + 0x17); // +0x5c

  // --- shell @ +0x04 ---
  TreeShell* shell04 = reinterpret_cast<TreeShell*>(b + 0x04);
  FUN_00440ab0(shell04, reinterpret_cast<void*>(shell04->head[1]));
  clear_tree_shell_head_selflink(shell04);

  // --- vectors @ +0x20 and +0x3c ---
  free_vector_triple(self + 0x8);  // +0x20
  free_vector_triple(self + 0xF);  // +0x3c

  // --- shell @ +0xA4 ---
  TreeShell* shellA4 = reinterpret_cast<TreeShell*>(b + 0xA4);
  FUN_00440d20(shellA4, reinterpret_cast<void*>(shellA4->head[1]));
  clear_tree_shell_head_selflink(shellA4);

  // --- owned objects @ +0xB0 / +0xB4 ---
  if (void* p = reinterpret_cast<void*>(self[0x2C])) {
    FUN_00988710(p);
    operator_delete(p);
  }
  self[0x2C] = 0;
  if (void* p = reinterpret_cast<void*>(self[0x2D])) {
    FUN_00988710(p);
    operator_delete(p);
  }
  self[0x2D] = 0;

  // --- optional detach ---
  if (self[0x22] != 0) { // +0x88
    FUN_00756be0(self);
  }

  // --- children vector @ +0x94 ---
  uint32_t* begin = reinterpret_cast<uint32_t*>(self[0x25]); // +0x94
  uint32_t* end   = reinterpret_cast<uint32_t*>(self[0x26]); // +0x98
  if (begin != nullptr && end != begin) {
    for (uint32_t* it = begin; it != end; ++it) {
      int r = FUN_0076d1b0(
          "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",
          0x73,
          "Window deleted with children still attached!");
      if (r == 3) {
        FILE* f = std::fopen("c:\\VOGCRASH.txt", "w");
        if (f) {
          std::fprintf(f,
                       "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
                       "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",
                       0x73, 1,
                       "Window deleted with children still attached!");
          std::fclose(f);
        }
        std::raise(0x16);
        ExitProcess(3);
      }
      uint32_t child = *it;
      *reinterpret_cast<uint32_t*>(child + 0x88) = 0; // clear parent link
    }
    free_vector_triple(self + 0x25);
  }

  // EH state = 6: residual erase of shell @ +0xA4 head
  {
    void* dummy[1];
    uint32_t* head = shellA4->head;
    FUN_00441960(dummy, reinterpret_cast<void*>(head[0]), head);
    operator_delete(head);
    shellA4->head = nullptr;
    shellA4->size = 0;
  }

  // EH residual re-free of children / +0x5c / +0x3c (idempotent nulls)
  free_vector_triple(self + 0x25);
  free_vector_triple(self + 0x17);
  free_vector_triple(self + 0xF);

  // EH state = 2: nested subobject vtbl @ +0x30
  self[0xC] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9db18); // +0x30
  if (int* rc = reinterpret_cast<int*>(self[0xD])) {
    rc[1] -= 1;
    if (rc[1] == 0) {
      void** vtbl = *reinterpret_cast<void***>(rc);
      reinterpret_cast<void(__thiscall*)(void*)>(vtbl[2])(rc);
    }
  }
  free_vector_triple(self + 0x8);

  // erase shell saved as +0x10
  {
    void* dummy[1];
    uint32_t* head = shell10->head;
    FUN_00441720(dummy, reinterpret_cast<void*>(head[0]), head);
    operator_delete(head);
    shell10->head = nullptr;
    shell10->size = 0;
  }

  // EH = -1: erase shell @ +0x04
  {
    void* dummy[1];
    uint32_t* head = shell04->head;
    // twin erase helper path (disasm CALL after EH=-1)
    FUN_00441720(dummy, reinterpret_cast<void*>(head[0]), head);
    operator_delete(head);
    shell04->head = nullptr;
    shell04->size = 0;
  }

  // SEH restore; ADD ESP,0x20; RET — host free is scalar peer only
}

// Ghidra twin name
extern "C" void __fastcall FUN_00759de0(uint32_t* self)
{
  gfxUIWindow_CompleteDtor(self);
}
