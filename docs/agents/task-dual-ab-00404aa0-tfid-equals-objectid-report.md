# Dual A/B report — `aa_00404aa0` TFID_EqualsObjectId

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00404aa0`. Dual A/B + artifacts. Seal leaf ObjectId/TFID equality.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404aa0` TFID_EqualsObjectId | **accept** — three-field equality + cdecl ABI sealed |

---

## Sealed facts

1. **ABI:** `__cdecl`, two stack pointers `pA` / `pB` (`[esp+4]`, `[esp+8]`), plain **`RET`**, return **`int` in EAX** (`1` equal / `0` unequal).

2. **Leaf:** **zero callees**, no globals, no side effects, body `0x00404aa0`–`0x00404ac6`.

3. **Algorithm (exact):**
   - `*(int32*)(pA+0) == *(int32*)(pB+0)`
   - `*(int32*)(pA+4) == *(int32*)(pB+4)`
   - `*(int8*)(pA+8)  == *(int8*)(pB+8)`
   - All true → `1`, else `0` (short-circuit).

4. **Not full TFID_16 memcmp:** pad **`+9..+15` are not compared**.

5. **No null checks** on `pA`/`pB`.

6. **Bytes ≡ decompile** (`read_memory` hex  
   `8b4424048b108b4c24083b1175168b50043b5104750e8a40083a41087506b801000000c333c0c3cc`).

7. **Sibling:** `TFID_NotEquals` (`0x0040b150`) = same three compares, inverted return.

8. **Invalid sentinel** `g_abTfidInvalid_A15870` @ `0x00a15870` =  
   `FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00` — matches equality fields for “invalid TFID” call sites.

9. **Name:** `TFID_EqualsObjectId` (Ghidra custom). Inferred fields: `dwCoidLo` / `dwCoidHi` / `bGlobal` (repo `TFID_16`).

10. **Call surface:** **38** xrefs; **22** named callers (skill cast/resolve, stance/gadget, status, NPC cast, vehicle net reconcile, collision, etc.).

---

## Gaps

1. Product English / PDB confirmation for `bGlobal` and symbol string.  
2. Whether any identity path outside this unit uses pad bytes `+9..+15`.  
3. Exhaustive per-call-site argument provenance (parent residual — not owned).  
4. Runtime live confirmation; bit-exact / image diff.  
5. Type quality in Ghidra still `void*` (not `TFID_16*`) — behavioral seal unaffected.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00404aa0_TFID_EqualsObjectId.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00404aa0_TFID_EqualsObjectId.md` | **accept** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00404aa0_TFID_EqualsObjectId.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00404aa0_TFID_EqualsObjectId.md` |
| Function record | `docs/reconstruction/functions/aa_00404aa0_TFID_EqualsObjectId.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TFID_EqualsObjectId.cpp` |
| Raw (authoritative body + v2026-07-29 append) | `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.md` |
| Annotated | `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.annotated.md` |
| Scratch | `tmp/a_00404aa0.md` |
| This report | `docs/agents/task-dual-ab-00404aa0-tfid-equals-objectid-report.md` |

---

## AutoCore impact

- Port **must** equality-check **CoidLo + CoidHi + BGlobal byte only** — not 16-byte sequence equality.
- Invalid-object tests should match sentinel `(-1, -1, 0)` via this same three-field contract.
- Do not invent null-safe wrappers if aiming for retail-fault parity; safe wrappers are a server-port policy choice, not client body.
- Inverse helper `TFID_NotEquals` is available at `0x0040b150` with identical field set.
