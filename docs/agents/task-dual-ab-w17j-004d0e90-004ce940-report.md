# Dual A/B report — W17-J OWN VAs `0x004d0e90` + `0x004ce940`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W17-J  
**Scope:** OWN ONLY VAs `0x004d0e90`, `0x004ce940`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Canonical | Verdict |
|------|-----------|---------|
| `aa_004d0e90` | `Object_EnqueueDeferredOnce` | **accept-with-gaps** — bit0 sticky + `host+0xe5fc` queue sealed |
| `aa_004ce940` | `CVOGLootGenerator_GetOrCreate` | **accept-with-gaps** — singleton ensure size `0xbc` + EAX return sealed |

---

## `aa_004d0e90` — Object_EnqueueDeferredOnce

### Sealed facts

1. **ABI:** `__thiscall` — **ECX** = host (queue at `+0xe5fc`); **stack** = `Object*`; **`ret 4`**.  
   Boundary: `0x004d0e90` … `0x004d0ec8` (`c2 04 00` + `CC`).

2. **Flag:** `ObjectFlag_DeferredQueued` = **`object+0x17c` bit 0** mask **`0x1`**.  
   Bytes: `test [esi+0x17c],1` / `or dword [esi+0x17c],1`.

3. **Queue field:** `host+0xe5fc` loaded into ECX before both callees (`8b 8f fc e5 00 00`).

4. **Idempotent path:** if bit0 set → return; else `FUN_004e15a0(queue,obj)` contains? if yes return; else `FUN_004024d0` append + set bit0.

5. **Not destroy:** no free/vcall; list node alloc is inside append callee only.

6. **Decompiler gap:** surface `void FUN_004d0e90(int)` drops ECX and mis-attributes callee this — **bytes win**.

7. **Live decompile body ≡ 2026-07-23 raw surface**; dual append records bytes correction.

### Gaps

1. Queue consumer / bit clear policy.  
2. Product names of queue class + node vtbl `009cb340`.  
3. Homogeneous host type across ~20 callers.  
4. Original PDB symbol.  
5. Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004d0e90_Object_EnqueueDeferredOnce.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004d0e90_Object_EnqueueDeferredOnce.md` |
| Function record | `docs/reconstruction/functions/aa_004d0e90_FUN_004d0e90.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EnqueueDeferredOnce.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004d0e90.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_004d0e90_FUN_004d0e90.md` |
| Annotated | `docs/reconstruction/raw/aa_004d0e90_FUN_004d0e90.annotated.md` |

---

## `aa_004ce940` — CVOGLootGenerator_GetOrCreate

### Sealed facts

1. **Role:** lazy **ensure/get** of global **`DAT_00b037e8`** (`CVOGLootGenerator` / loot manager).

2. **ABI:** no stack args; plain **`c3`**; return **EAX** = singleton (0 on OOM).  
   Boundary: `0x004ce940` … `0x004ce9b2`.

3. **Size:** `operator_new(**0xbc**)` — imm `68 bc 00 00 00`.

4. **Ctor:** `__thiscall FUN_0050c1b0(mem, DAT_00b041fc)` then `mov DAT_00b037e8, eax`.  
   Peer duals: `LootManager_ctor_Inferred`, `CVOGSectorMap_InitGenerators` (same global/size).

5. **Decompiler gaps:** typed **void**; `ExceptionList = pvVar1` is SEH artifact — **bytes win**.

6. **Live decompile body ≡ 2026-07-23 raw surface**; dual append records EAX return seal.

7. **Not** reaction-dispatch/network helper (scaffold parent name overstated; ~40 diverse callers).

### Gaps

1. Unlocked first-create race.  
2. Destroy/lifetime of singleton.  
3. Full type of `DAT_00b041fc`.  
4. Original PDB symbol exact string.  
5. Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004ce940_CVOGLootGenerator_GetOrCreate.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004ce940_CVOGLootGenerator_GetOrCreate.md` |
| Function record | `docs/reconstruction/functions/aa_004ce940_FUN_004ce940.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetOrCreate.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004ce940.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_004ce940_FUN_004ce940.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce940_FUN_004ce940.annotated.md` |

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## AutoCore impact

- **Deferred queue bit0** at `object+0x17c`: client teardown / reaction paths mark objects for later processing; server mirrors should not confuse this with **Broken** (`0x80000`) or dirty (`0x20000`).
- **Loot generator singleton:** client content tables load via `CVOGLootGenerator` ensure; server loot rolls already have separate paths — do not invent a second client-style global unless implementing client fidelity tools.
- Prefer named clean sources over old `Named_CalleeOf_*` scaffolds for these VAs.
