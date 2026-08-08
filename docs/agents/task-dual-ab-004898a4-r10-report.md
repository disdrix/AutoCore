# Dual A/B report — R10-011 OWN-ONLY (`0x004898a4`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-011**  
**Scope:** VA `0x004898a4` (`aa_004898a4`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `get_xrefs_from` + `get_bulk_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R10 — undualed callee of dualed parent `0x00938670`; inventory name `__RTDynamicCast`; system interaction-activation.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004898a4` `__RTDynamicCast` | **accept-with-gaps** — 6 B IAT thunk + CRT name + cdecl 5-arg ABI sealed; CRT body external; full caller TypeDescriptor census + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-recursive / in-image-cast-math / `void(void)` / product-rename / exclusive-interaction claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004898a4` — sealed facts

1. **Body:** `0x004898a4`–`0x004898a9` inclusive (**6 B**); `FF 25 48 66 9C 00` = `jmp dword ptr [0x009C6648]`.
2. **Classification:** **IAT thunk** (`is_thunk=true`); Ghidra name `__RTDynamicCast`.
3. **IAT:** `PTR___RTDynamicCast_009c6648` @ `0x009c6648` → EXTERNAL `__RTDynamicCast` (MSVC CRT). Snapshot target `0x006ea91e` is load-resolved CRT, not dualled.
4. **ABI (call sites):** **cdecl**, **5 stack args**, caller **`ADD ESP,0x14`**; result **EAX** pointer or NULL for pointer casts (`isReference==0`).
5. **CRT contract:**
   ```c
   void* __cdecl __RTDynamicCast(void* inptr, long VfDelta,
       void* srcType, void* targetType, int isReference);
   ```
6. **Name:** `__RTDynamicCast` — official MSVC export; **no** `_Inferred`; **no** product invent.
7. **Decompiler ≠ machine:** recursive-call / void prototype are IAT-recovery artifacts; bytes + xrefs authority.
8. **Callers:** ≥100 sites (skills/UI/inventory/missions/interaction). Parent evidence `FUN_00938670` @ `0x009386d6`: cast `CVOGClonedObjectBase` → `CVOGStore`, `VfDelta=0`, `isReference=0`.

### Gaps

- External CRT implementation / DLL version.  
- Exhaustive TypeDescriptor pair inventory across all call sites.  
- Ghidra stored prototype repair (`void(void)`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004898a4___RTDynamicCast.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004898a4___RTDynamicCast.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.md` |
| Annotated | `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/__RTDynamicCast.cpp` |
| Function named | `docs/reconstruction/functions/aa_004898a4___RTDynamicCast.md` |
| Function address-form | `docs/reconstruction/functions/aa_004898a4_FUN_004898a4.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00938670  [0x00938670]  parent dual (interaction) — NOT dualled here
  ├─ Object_ResolveFromTFID
  ├─ __RTDynamicCast  [0x004898a4]  OWN R10-011  (IAT → CRT)
  │     src  = CVOGClonedObjectBase::RTTI_Type_Descriptor
  │     dst  = CVOGStore::RTTI_Type_Descriptor
  │     VfDelta=0, isReference=0
  └─ VehicleEntity_* / UI / FUN_007fef20  (parent body only)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004898a4-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004898a4` | **Do not port the IAT trampoline as game logic.** Use C++ `dynamic_cast` / equivalent type checks. When matching retail call sites, preserve **cdecl 5-arg** + NULL-on-fail for pointer casts. Name remains **`__RTDynamicCast`**. |
| Pair with | parent interaction flow `0x00938670` (not dualled here); all product sites that already emit RTTI descriptors. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` (CRT name already correct)
- `systems/interaction-activation.md` residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004898a4`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + IAT xrefs + assembly context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean documents IAT shape + CRT contract; no product rename.
- Odd behavior preserved: decompiler recursive-call display left as non-authority.
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
