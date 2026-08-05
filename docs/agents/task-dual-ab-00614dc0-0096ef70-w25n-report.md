# Dual A/B report — W25-N OWN-ONLY (`aa_00614dc0`, `aa_0096ef70`)

**Date:** 2026-07-29  
**Agent:** W25-N OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00614dc0`, `0x0096ef70`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `reviews/WAVE_2026-07-29_wave25_partition_map.md` → W25-N  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00614dc0` Skill_HB_SpawnEntities_ctor_Inferred | **accept** — 119 B SEH ctor: base `CVOGHBSkillBase_ctor` + vtbl `009d0ec4` + ushort `@+0x6c4`, `ret 0x18` |
| `aa_0096ef70` RefCountedPtr_DefaultCtor_Inferred | **accept** — 9 B: `*this=0`, ECX handle, return this; ~62 xrefs |

---

## Sealed facts — `0x00614dc0`

1. **ABI:** **`__thiscall`** `this` in **ECX**; **six** stack formals; **`ret 0x18`**. Return **`this*`** in EAX.

2. **Body:** Ghidra `0x00614dc0`–`0x00614e36` (**119 bytes** inclusive of `ret 0x18`).

3. **Base:** `CVOGHBSkillBase_ctor` @ `0x005788d0` — rel32 **Confirmed** (`E8 CD 3A F6 FF` @ `0x00614dfe`).

4. **Subclass vtbl:** `*this = PTR_FUN_009d0ec4` (**Confirmed** imm). Peer slots: precheck `+0x1c` → `0x006170b0`; execute `+0x2c` → `0x00615020`.

5. **Extra field:** skill object `vfunc+0x27c` → store **uint16** at **`this+0x6c4`**.

6. **Sole caller:** `Skill_HB_SpawnEntities_Execute_Inferred` @ `0x00615b97` — `operator_new(0x6d0)` then this ctor.

7. **Name:** `Skill_HB_SpawnEntities_ctor_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00614dc0`.

---

## Sealed facts — `0x0096ef70`

1. **ABI:** **ECX** = handle*; **no** stack formals; **`ret`**. Return **this** in EAX (decomp `void` understates).

2. **Body:** `0x0096ef70`–`0x0096ef78` (**9 bytes**): `8B C1` / `C7 00 00 00 00 00` / `C3`.

3. **Behavior:** `*this = 0` only. No callees.

4. **Role:** default ctor of **refcounted handle** — peer dtor `FUN_0096efd0` releases payload refcount (context; not dual-owned here).

5. **Callers:** ~**62** sites (TacArc×2, paint, graphics, assets, UI, …).

6. **Name:** `RefCountedPtr_DefaultCtor_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_0096ef70`.

---

## Gaps

### `00614dc0`
1. Product RTTI English for `PTR_FUN_009d0ec4` subclass.  
2. Semantic of skill vfunc `+0x27c` / consumers of `this+0x6c4`.  
3. Runtime / bit-exact / differential — open.

### `0096ef70`
1. Product type name of refcounted payload.  
2. Full dual of dtor `0096efd0`.  
3. Whether some sites re-null without dtor.  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00614dc0` | `reviews/A_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` | `reviews/B_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` | **accept** |
| `0x0096ef70` | `reviews/A_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` | `reviews/B_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` | **accept** |

---

## Files

### `aa_00614dc0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00614dc0_FUN_00614dc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_SpawnEntities_ctor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00614dc0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00614dc0_FUN_00614dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00614dc0_FUN_00614dc0.annotated.md` |

### `aa_0096ef70`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0096ef70_FUN_0096ef70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RefCountedPtr_DefaultCtor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0096ef70.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0096ef70_FUN_0096ef70.md` |
| Annotated | `docs/reconstruction/raw/aa_0096ef70_FUN_0096ef70.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00614dc0-0096ef70-w25n-report.md` |

---

## AutoCore impact

### `00614dc0`
- Client skill HB residual for multi-entity spawn execute.
- Preserve **base then subclass vtbl** order and **`0x6d0`** size if mirroring HB list arming.
- Do not conflate with execute (`00615020`) or precheck (`006170b0`) — this is construction only.
- Gate path: only from spawn execute after creature/template placement.

### `0096ef70`
- Shared null-init for embedded refcounted handles (UI/graphics/TacArc/etc.).
- Ports should treat as **pointer null only**, not full object memset.
- Pair with dtor semantics when releasing payload (peer `0096efd0`).

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x005788d0` | `CVOGHBSkillBase_ctor` (base) |
| `0x00615020` | SpawnEntities Execute (vtbl+0x2c) |
| `0x006170b0` | SpawnEntities Precheck (vtbl+0x1c) |
| `0x009d0ec4` | Subclass vtbl |
| `0x0096efd0` | Refcounted handle dtor (peer) |
| `0x0096f530` | Related but larger init (dword + flags) |

---
