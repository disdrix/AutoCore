# Review A (reconstruction fidelity): `aa_007a4400` Perf_QpcBeginNamed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4400` |
| **VA** | `0x007a4400`–`0x007a445c` |
| **Canonical name** | `Perf_QpcBeginNamed_Inferred` |
| **Ghidra name** | `FUN_007a4400` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-D) |
| **Counterpart** | `reviews/B_aa_007a4400_Perf_QpcBeginNamed_Inferred.md` |
| **System** | perf / QPC named begin |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Named performance-timer **begin**:

1. Once-init: if `DAT_00b00a74` ≠ 0 → clear, `QueryPerformanceFrequency`, store `g_flOne/freq` at `DAT_00afa254`.
2. Copy `label` into `slot+8`.
3. `QueryPerformanceCounter(slot)`.
4. Return `slot` in EAX.

High-mention stage marker across client init and sector map work.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007a4400_FUN_007a4400.md` (+ 2026-07-29 W26-D append) |
| Annotated | `docs/reconstruction/raw/aa_007a4400_FUN_007a4400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Perf_QpcBeginNamed_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007a4400.cpp` |
| Function record | `docs/reconstruction/functions/aa_007a4400_FUN_007a4400.md` |
| Named record | `docs/reconstruction/functions/aa_007a4400_Perf_QpcBeginNamed_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` 92 B; epilogue `C2 04 00` |

---

## 3. Signature (sealed)

```c
// thiscall; 1 stack formal; ret 4; EAX = this
LARGE_INTEGER *Perf_QpcBeginNamed_Inferred(LARGE_INTEGER *slot /*ECX*/, char *label);
```

| Formal | Source | Conf |
|---|---|---|
| slot | ECX | **High** |
| label | Stack[0x4] | **High** |
| return | EAX = slot | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if DAT_00b00a74:
  DAT_00b00a74 = 0
  QPF → DAT_00afa254 = 1.0f / freq
strcpy(slot+8, label)
QPC(slot)
return slot
```

| Stage | Match | Conf |
|---|---|---|
| Once-init gate + reciprocal | **Yes** | **High** |
| Label to slot+8 | **Yes** | **High** |
| QPC stamp at slot+0 | **Yes** | **High** |
| Only Win32 callees | **Yes** | **High** |
| ret 4 thiscall | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **92 B** hex:
```
83ec08803d740ab00000568bf174228d44240450c605740ab00000ff15b4619c00df6c2404d83da0f2a000d91d54a2af008b4424108d56082bd08d9b000000008a08880c0283c00184c975f456ff15b0619c008bc65e83c408c20400
```

Epilogue: `8B C6 5E 83 C4 08 C2 04 00` (EAX=ESI/this; pop esi; add esp,8; ret 4).

IAT: `[0x009c61b4]` QPF, `[0x009c61b0]` QPC.

---

## 6. Gaps

- Product English / original plate for the timer type.
- End/stop consumer of `DAT_00afa254` (not OWN).
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, slot layout, once-init globals, and high-xref role sealed. Naming is evidence-backed **INFERRED**. → **accept**.
