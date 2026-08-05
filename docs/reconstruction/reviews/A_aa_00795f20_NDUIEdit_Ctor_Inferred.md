# Review A (reconstruction fidelity): `aa_00795f20` NDUIEdit_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00795f20` |
| **VA** | `0x00795f20` |
| **Canonical name** | `NDUIEdit_Ctor_Inferred` (Ghidra `FUN_00795f20`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00795f20_NDUIEdit_Ctor_Inferred.md` |
| **System** | `client-ui` / NDUI edit / text entry |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** **Edit / text-entry subclass constructor**. Base `FUN_007b5dd0` → clear edit flags → install vtbl `PTR_FUN_00a98b1c` → font metrics `DAT_00d1e7a8/ac`.

CreateChildWidgets allocate **`operator_new(0x4a4)`** then this for digit editors (Trade credit digits), rank/level/password edits (Arena prefs), etc. Post-setup often sets `child+0x48b = 1` and digit index via vtbl.

---

## 2. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00795f20_FUN_00795f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00795f20_FUN_00795f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00795f20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00795f20_FUN_00795f20.md` |
| Live | decompile ≡ raw (23 insn, 1 BB, CC 1) |

---

## 3. Signature / flow

```c
// Recovered: this in ESI, cookie in EAX (same lost-formal pattern as button)
void * NDUIEdit_Ctor(void *this, undefined4 cookie);
```

| Stage | Conf |
|---|---|
| `FUN_007b5dd0(this, cookie)` | **High** |
| Zero edit flags: `+0x488` dword area, `+0x489..0x48d`, `+0xd9` | **High** |
| Zero `+0x490..+0x4a0` dwords (`[0x124]..[0x128]`) | **High** |
| Vtbl `PTR_FUN_00a98b1c` | **High** |
| Metrics `[0x8a]/[0x8b] = DAT_00d1e7a8/ac` (≠ button’s b0/b4) | **High** |

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = edit ctor | **High** | size 0x4a4 + credit/rank edit factories |
| Distinct from button | **High** | different vtbl + metrics globals |
| Flag semantics at +0x48b | **Probable** | callers set “enabled” after ctor |
| Runtime | **Open** | — |

---

## 5. Gaps

1. Product class name.
2. Buffer/caret fields among zeroed dwords.
3. Formal ABI (ESI/EAX recovered, not in decompiler prototype).
