# Review B (skeptical / adversarial): `aa_00409b40` StdVector_UninitCopyTrampoline_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-008) |
| **Counterpart** | `reviews/A_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler 3-param `__fastcall` is complete ABI | **Falsified** — 2 stack args + **`RET 8`**; decomp drops second stack formal and void-washes EAX |
| 2 | This body is the real uninit_copy loop | **Falsified** — 27 B wrapper; only CALL `0040a590` + cleanup |
| 3 | ECX is meaningful for copy semantics | **Narrow** — forwarded/pushed but **unused** by target body (InsertN this glue only) |
| 4 | Same as direct `0040a590` call sites | **Narrow** — same worker, different ABI surface (RET 8 trampoline vs plain RET free helper) |
| 5 | Merge with Elem0x28 trampoline `00409ae0` | **Falsified** — CALL targets differ (`0040a590` vs `0040a520`); InsertN parent uses `/0xc` |
| 6 | Merge with ConstructN / Ufill | **Falsified** — no fill/construct; pure range forward |
| 7 | thiscall member of vector | **Falsified** — free helper trampoline; ECX not required by worker |
| 8 | Returns void | **Falsified** — EAX = dest_end from worker; InsertN stores `[EBP-0x1c]` then feeds Ufill |
| 9 | Invent product English name without PDB | **Rejected** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline-only CF | **High** | Invented element math |
| ABI RET 8 + EDX dest | **High** | Stack corruption |
| Target 0040a590 / 0x0C family | **High** | Wrong stride |
| Product T English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against InsertN parent

```
// FUN_004082f0 grow (sites 0x00408413 / 0x0040843a):
//   new = operator_new(cap*0xc)
//   trampoline(this, new, begin, where)     // prefix
//   Ufill(this, template)                    // middle 00406ee0
//   trampoline(this, after, where, end)      // suffix
//   operator_delete(old); write triad
// Non-grow paths call 0040a590 directly without this trampoline.
// Parent dualed WQ9H-B as StdVector_InsertN_Elem12_Inferred.
```

---

## 4. Surviving contract for AutoCore

```
// Port as ABI glue only — do not reimplement the 0x0C loop here:
void* StdVector_UninitCopyTrampoline_Elem12(
    void* /*this unused*/, void* dest,
    const void* begin, const void* end) {
  return StdVector_UninitializedCopy_Elem12(/*ECX*/ end, begin, dest);
}
// RET 8 at call boundary. Keep distinct from free-helper entry 0040a590
// and from 0x28 twin trampoline 00409ae0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles. Residual product T → **accept-with-gaps**.
