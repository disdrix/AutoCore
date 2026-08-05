# Review A (reconstruction fidelity): `aa_0040ddd0` UI_ClampS16_At142_Max200_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ddd0` |
| **VA** | `0x0040ddd0` |
| **Canonical name** | `UI_ClampS16_At142_Max200_Inferred` (Ghidra `FUN_0040ddd0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040ddd0_UI_ClampS16_At142_Max200_Inferred.md` |
| **System** | `client-ui` / char sheet / attribute points |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High (CF).** Tiny **getter with clamp**:

```c
int __fastcall FUN_0040ddd0(int this) {
  int v = (int)*(short *)(this + 0x142);
  if (199 < *(short *)(this + 0x142))  // signed short > 199
    v = 200;
  return v;
}
```

Returns the signed 16-bit value at **`this+0x142`**, capped at **200**.

**Not a widget constructor.** Prior CharSheet CreateChildWidgets notes that labeled this as child ctor after `operator_new(0x488)` are **wrong for this VA** — body is 6 instructions, no allocation, no vtbl.

---

## 2. Callers (High)

| Caller | VA | Context |
|---|---|---|
| `CDlgCharSheet2d_CreateChildWidgets` | `0x008faaf0` | Char sheet build (uses clamp result, not as ctor) |
| `UI_OnAttributePointClick_Inferred` | `0x008f92e0` | Attribute spend click path |
| `FUN_008f97c0` | `0x008f97c0` | Sibling attr-UI helper |

Strong association with **character / attribute-point UI** (cap 200 matches attribute-point style limits). Exact object type at ECX still residual (character blob vs sheet host vs attr subobject).

---

## 3. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040ddd0_FUN_0040ddd0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040ddd0_FUN_0040ddd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040ddd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040ddd0_FUN_0040ddd0.md` |
| Live | decompile ≡ raw (6 insn, 3 BB, CC 2, 0 calls) |

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| CF: read s16 @ +0x142, clamp max 200 | **High** | live ≡ raw |
| `__fastcall` this in ECX | **High** | decompiler |
| Not a ctor | **High** | body + size |
| Attr-point related | **Probable** | AttrPointClick + CharSheet callers |
| Field English name | **Tentative** | “available points” / “level” residual |
| Runtime | **Open** | — |

---

## 5. Gaps

1. Owning C++ type for `this`.
2. Whether value is attribute points, level, or UI counter.
3. Call-site use of return in CharSheet body (decomp blocked on parent).
