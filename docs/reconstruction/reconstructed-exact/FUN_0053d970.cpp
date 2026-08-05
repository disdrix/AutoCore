// =============================================================================
// Object_SetPhysBodyTypeIfNotReady_Inferred  (Ghidra: FUN_0053d970)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d970
// Address:   0x0053d970  (autoassault.exe, image base 0x400000)
// System:    physics / entity shell
// Generated: 2026-07-29 dual A/B — machine CF (read_memory); decompiler incomplete
// Exactness: Behavior-preserving rewrite of machine control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   If entity has a phys shell that is not fully ready, tail-request body type
//   1 (flag==0) or 6 (flag!=0) via FUN_005d4440(phys, type). Fully ready or
//   null phys → no-op. Used by vehicle type-6 ghost leave (flag 0), spawn/create
//   type-6 enter (flag 1), creature post-create, etc.
//
// ABI: MSVC __thiscall — ECX = entity; one stack int; RET 4.
// Soft-ready: (phys+0x40 == 0) || (phys+0x08 == 0)  — twin of network soft path.
//
// Callee: FUN_005d4440 @ 0x005d4440 (leave-FUN for full body/AI switch).

// READABILITY:
//  - Body ~0x3D bytes; dual readiness gate; flag→{1,6}; tail jmp.
//  - Notable callees: FUN_005d4440 (tail).
//  - Return sites: early RET 4, or return from tail callee.

/*
 * Behavioral notes:
 * - Ghidra decompile drops stack flag and shows FUN_005d4440() with no args —
 *   that form is incorrect for ports. Machine rewrite is authoritative.
 * - flag is a boolean selector, not a type id.
 * - Runtime / differential verification: OPEN.
 */

typedef int BOOL32;

/* Phys shell + entity are opaque here; offsets only. */
struct PhysShell_Inferred;
struct CVOGObject_Inferred;

/* Leave-FUN: thiscall phys, stack target body type. */
void __thiscall FUN_005d4440(PhysShell_Inferred *phys, int targetBodyType);

void __thiscall Object_SetPhysBodyTypeIfNotReady_Inferred(
    CVOGObject_Inferred *entity,
    int flag)
{
  PhysShell_Inferred *phys;
  int targetBodyType;

  phys = *(PhysShell_Inferred **)((char *)entity + 0x08);
  if (phys == (PhysShell_Inferred *)0x0) {
    return;
  }

  /* Fully ready: non-zero ready byte AND non-null secondary field. */
  if ((*(unsigned char *)((char *)phys + 0x40) != 0)
      && (*(void **)((char *)phys + 0x08) != (void *)0x0)) {
    return;
  }

  /* Machine: mov [esp+4],6; if original flag==0 → mov [esp+4],1; jmp 5d4440 */
  if (flag == 0) {
    targetBodyType = 1;
  } else {
    targetBodyType = 6;
  }

  /* Tail-call in retail (JMP); written as call for readable C with same args. */
  FUN_005d4440(phys, targetBodyType);
}
