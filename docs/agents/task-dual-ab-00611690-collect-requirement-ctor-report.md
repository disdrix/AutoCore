# Dual A/B report — `aa_00611690` CVOGObjectiveRequirement_Collect_ctor (type **2**)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00611690`. Dual A/B + artifacts. Seal **RequirementType = 2**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/xrefs/assembly_context). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00611690` CVOGObjectiveRequirement_Collect_ctor | **accept-with-gaps** — **type=2 + vtable + ABI + size 0x68 sealed** |

---

## Sealed facts

1. **RequirementType = 2** written as dword at **`this+0x0c`**  
   (`C7 46 0C 02 00 00 00`). Collect — not Deliver (3).

2. **Vtable** `*this = 0x009e12c4` (`PTR_FUN_009e12c4`) after base ctor; RTTI  
   `.?AVCVOGObjectiveRequirement_Collect@@` @ `0x00afe9ac`.

3. **ABI:** MSVC **`__thiscall`**, stack **`parent`**, epilogue **`RET 4`**, return **`this`** in **EAX**.

4. **Base:** `FUN_00637da0(parent)` sets temporary base vfptr `0x009e3bac` and **`this+0x04 = parent`**, then Collect overwrites vfptr.

5. **Defaults (pre-XML):**
   - `+0x10` item CBID = **`0xFFFFFFFF`**
   - `+0x14` NumToCollect = **0**
   - `+0x48` OptionalDropPercent = **0.0f** (`movss`, not int zero of decompiler `param_1[0x12]`)
   - Large sentinel block of **`−1`** dwords and several **u8 0** flags

6. **Sole production caller:** factory `FUN_00547050` @ **`0x00547337`**:
   - Wide string match **`u"collect"`** @ `0x009d0b34`
   - **`PUSH 0x68`** → alloc **104** bytes
   - Parent from objective table `def+0x13c[index]`

7. **No** inventory count, packet, or progress math in this unit.  
   Eval `0x00611940` / SlotAction `0x006124b0` / Action `0x00611f20` / XML `0x00611a00` own those.

8. **Name:** `CVOGObjectiveRequirement_Collect_ctor` (**High** — RTTI + registry). Deprecate bare `FUN_00611690` for new refs.

---

## Gaps

1. Product English names for most **`−1`** pad fields (`+0x20`..`+0x44`, tail).  
2. **`this+0x08` unwritten** by ctor — allocator zero policy unknown.  
3. Full factory type-dispatch table (parent residual beyond collect/deliver/kill_aggregate).  
4. Base class product name for `FUN_00637da0` / `PTR_LAB_009e3bac`.  
5. Runtime live construction; bit-exact / image diff.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Collect_ctor.cpp` |
| Raw (authoritative body + residual) | `docs/reconstruction/raw/aa_00611690_FUN_00611690.md` |
| Annotated | `docs/reconstruction/raw/aa_00611690_FUN_00611690.annotated.md` |
| Scratch | `tmp/a_00611690.md` |
| This report | `docs/agents/task-dual-ab-00611690-collect-requirement-ctor-report.md` |

Legacy scaffold (name superseded for new work):  
`functions/aa_00611690_FUN_00611690.md`, `reconstructed-exact/FUN_00611690.cpp`.

Related: `reviews/CHAIN_2026-07-29_inventory_collect.md`; system map `systems/missions-progression.md` / `inventory-transfer.md`.

---

## AutoCore impact

- Client Collect requirement identity is **type code 2** + class Collect — mirror any server/GLM `RequirementType` enum accordingly.  
- Defaults before XML: CBID **invalid (−1)**, count target **0**, drop% **0** — do not treat ctor alone as a playable collect objective.  
- Object size **0x68** for Collect instances in client factory path.  
- Do not reuse Deliver type **3** paths (`0x00610bc0` / cargo-ready) for Collect construction.
