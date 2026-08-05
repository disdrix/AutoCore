# Review B (skeptical / adversarial): `aa_00404510` UiToast_UninitializedCopy_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-G) |
| **Counterpart** | `reviews/A_aa_00404510_UiToast_UninitializedCopy_0x98.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This VA is the pod-copy leaf | **Falsified** — leaf is `FUN_00404710`; this only calls `FUN_004047a0` |
| 2 | Element size 4 / dword vector | **Falsified** — worker stride **0x98** |
| 3 | Fills from a single template value | **Falsified** — range-to-range copy; fill is `0x00404130` / ConstructN |
| 4 | Owns growth / `operator_new` | **Falsified** — pure copy helper |
| 5 | Same as fill-n `00404130` | **Falsified** — different callee (`004047a0` vs `00404670`) |
| 6 | True thiscall with meaningful `this` result | **Falsified** — `ret 0x0C`; ECX only phantom-pushed |
| 7 | Mission/XP/craft logic | **Falsified** — POD relocate only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline-only body | **High** | Mis-assign complexity to wrong VA |
| 0x98 via callee | **High** | Misaligned toast buffer |
| Distinct from fill-n / assign helpers | **High** | Corrupt insert semantics (`00404130` / `00404530`) |
| Free 3-arg ABI | **High** | Wrong calling convention in port |
| Formal names from Ghidra | **Low** | Do not trust thiscall param labels |

---

## 3. Cross-check against raw / live

```
raw ≡ live: single CALL to 0x004047a0 then return.
FUN_004047a0: loop +0x98, FUN_00404710(dst, src).
Parent InsertN dual lists this VA as relocate helper (×4 sites).
Twin 004044c0 same trampoline pattern at stride 0x38.
bytes: call 004047a0; add esp,0x14; ret 0x0C
```

---

## 4. Surviving contract for AutoCore

```
UiToast_UninitializedCopy_0x98(srcBegin, srcEnd, dst):
  // trampoline → FUN_004047a0
  copy each 0x98 POD from [srcBegin,srcEnd) into consecutive dst slots
  used by UiToastVector_InsertN realloc / shift paths
```

Port as span relocate of toast records; do **not** allocate, free, or template-fill here.

---

## 5. Open questions

1. Seal formal ABI map from parent call sites only (not decompiler formals).
2. Optional dual on `FUN_004047a0` if still scaffold-only.

**Verdict:** **accept-with-gaps**
