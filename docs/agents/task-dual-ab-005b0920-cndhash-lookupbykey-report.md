# Dual A/B report — `aa_005b0920` CNDHash_LookupByKey

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x005b0920`. Dual A/B + artifacts. Seal generic CNDHash **lookup-by-key** ABI, offsets, and control flow.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ xrefs/callees/function meta). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (single image; dual A/B = independent fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b0920` CNDHash_LookupByKey | **accept** — leaf lookup **sealed** |

---

## Sealed facts

1. **ABI:** `__thiscall` — `this` in ECX, stack **`uint32_t key`**, epilogue **`RET 4`**, return **value `void*`** in EAX or **NULL**.

2. **Leaf:** **zero callees**. No logging, no lock, no allocation.

3. **Bucket index:** `(uint32)(*(this + 0x08) & key)` then load `*( *(this + 0x10) + index*4 )` (bucket header), then chain head `*(bucketHdr + 0x04)`.

4. **Chain walk:** while node non-null, compare `key` to `*(node + 0x10)`; on mismatch follow `*(node + 0x0c)`; on match return `*(node + 0x08)` (value).

5. **Hash function (this unit):** **mask AND only** — no multiply/rotate mixing inside Lookup.

6. **Layouts sealed (fields this unit touches):**
   - Hash: `+0x08` mask, `+0x10` buckets array ptr  
   - Bucket header: `+0x04` head  
   - Node: `+0x08` value, `+0x0c` next, `+0x10` key  

7. **Cross-check:** `CNDHash_Insert` (`0x0053c560`) writes the same node offsets and prepends at `bucket+4` (Lookup first-match = newest on normal Insert path).

8. **Name:** Ghidra/plate **`CNDHash_LookupByKey`** is correct (returns value, not node). Plate mention of USContinentUnlocked is **usage example**, not sole consumer (**200+** call sites across missions, unlock, skills, UI, etc.).

9. **Machine body:** `0x005b0920`–`0x005b0953`; entry bytes  
   `8B41088B5424048B491023C28B04818B4004…` ending success path `8B4008 C20400`.

10. **Not sealed here (out of unit):** full object sizes, ctor/mask invariant, lock field `+0x1d` (used by Insert/walkers, **not** Lookup), complete caller product catalog.

---

## Gaps

1. Power-of-two capacity / mask invariant (ctor / resize not owned).  
2. Full bucket-header and node type sizes / vtable product names.  
3. Exhaustive caller→hash-instance map (offsets like char `+0x534` are caller-owned).  
4. Runtime live verification / bit-exact image diff.  
5. Behavior if corrupt null bucketHdr pointer (would crash; not handled).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b0920_CNDHash_LookupByKey.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b0920_CNDHash_LookupByKey.md` | **accept** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b0920_CNDHash_LookupByKey.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b0920_CNDHash_LookupByKey.md` |
| Function record | `docs/reconstruction/functions/aa_005b0920_CNDHash_LookupByKey.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_LookupByKey.cpp` |
| Raw (authoritative body) | `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.md` |
| Annotated + residual | `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.annotated.md` |
| This report | `docs/agents/task-dual-ab-005b0920-cndhash-lookupbykey-report.md` |

Sibling layout context (not owned): `CNDHash_Insert` `aa_0053c560` / `docs/reconstruction/reconstructed-exact/CNDHash_Insert.cpp`.

---

## AutoCore impact

- Client dictionary-style tables (missions completed, continent unlock bits, skill registry, interact TFID maps, etc.) all go through this **same** leaf.
- Server can implement as `Dictionary<uint, T>` / `TryGetValue` with **null miss** semantics; bucket layout only needed for client-memory tooling.
- Do not add traversal-lock requirements on pure lookup ports unless matching a locked walker path.
- Duplicate-key policy: Lookup returns **first chain hit**; Insert prepends → newest wins on standard Insert.
