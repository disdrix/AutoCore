# Review B (skeptical / adversarial): `aa_00409ae0` StdVector_UninitCopyTrampoline_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409ae0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-A) |
| **Counterpart** | `reviews/A_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler 3-param `__fastcall` is complete ABI | **Falsified** — 2 stack args + **`RET 8`**; decomp drops second stack formal |
| 2 | This body is the real uninit_copy loop | **Falsified** — 27 B wrapper; only CALL `0040a520` + cleanup |
| 3 | ECX is meaningful for copy semantics | **Narrow** — forwarded/pushed but **unused** by target body (InsertN this glue only) |
| 4 | Same as direct `0040a520` call sites | **Narrow** — same worker, different ABI surface (RET 8 trampoline vs plain RET free helper) |
| 5 | Merge with Elem12 range `0040a590` | **Falsified** — target is 0x28 worker; InsertN uses `/0x28` |
| 6 | Merge with ConstructN / Ufill | **Falsified** — no fill/construct; pure range forward |
| 7 | thiscall member of vector | **Falsified** — free helper trampoline; ECX not required by worker |
| 8 | Returns void | **Falsified** — EAX = dest_end from worker; InsertN stores `[EBP-0x1c]` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline-only CF | **High** | Invented element math |
| ABI RET 8 + EDX dest | **High** | Stack corruption |
| Target 0040a520 / 0x28 family | **High** | Wrong stride |
| Product T English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against InsertN parent

```
// FUN_00408050 grow (sites 0x00408171 / 0x00408198):
//   new = operator_new(cap*0x28)
//   trampoline(this, new, begin, where)     // prefix
//   Ufill(this, template)                    // middle
//   trampoline(this, after, where, end)      // suffix
//   operator_delete(old); write triad
// Non-grow paths call 0040a520 directly without this trampoline.
```

---

## 4. Surviving contract for AutoCore

```
// Port as ABI glue only — do not reimplement the 0x28 loop here:
void* StdVector_UninitCopyTrampoline_Elem0x28(
    void* /*this unused*/, void* dest,
    const void* begin, const void* end) {
  return StdVector_UninitializedCopy_Elem0x28(/*ECX*/ end, begin, dest);
}
// RET 8 at call boundary. Keep distinct from free-helper entry 0040a520.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles. Residual product T → **accept-with-gaps**.
