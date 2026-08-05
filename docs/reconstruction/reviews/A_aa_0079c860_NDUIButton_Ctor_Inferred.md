# Review A (reconstruction fidelity): `aa_0079c860` NDUIButton_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079c860` |
| **VA** | `0x0079c860` |
| **Canonical name** | `NDUIButton_Ctor_Inferred` (Ghidra `FUN_0079c860`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0079c860_NDUIButton_Ctor_Inferred.md` |
| **System** | `client-ui` / NDUI button |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** **Button subclass constructor**: calls base `FUN_007b5dd0`, installs button vtbl `PTR_FUN_00a97c34`, initializes button-only state (state-color bytes 0xFF, small flag zeros, scale `DAT_00a0f734` @ 0.9f pattern, font metrics `DAT_00d1e7b0/b4`).

CreateChildWidgets allocate **`operator_new(0x4cc)`** then this ctor for radios/checks/action buttons (Arena prefs host/close/ready; Trade ready/accept/cancel; etc.).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0079c860_FUN_0079c860.md` |
| Annotated | `docs/reconstruction/raw/aa_0079c860_FUN_0079c860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0079c860.cpp` |
| Function record | `docs/reconstruction/functions/aa_0079c860_FUN_0079c860.md` |
| Live | decompile ≡ raw |

---

## 3. Signature / ABI

```c
// Decompiler loses formals (unaff_ESI = this, in_EAX = cookie → base)
// Recovered from callers + base signature:
void * NDUIButton_Ctor(void *this, undefined4 cookie);
// returns via base; size class 0x4cc
```

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_007b5dd0(this, cookie)` first | **High** | sole callee |
| Overwrites vtbl → `PTR_FUN_00a97c34` | **High** | first store after base |
| 74 insn / 3 BB / CC 2 | **High** | signature |
| Size `0x4cc` in CreateChildWidgets | **High** | Arena/Trade duals |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Base ctor | Yes | **High** |
| Button vtbl install | Yes | **High** |
| ~10× RGBA-ish 0xFF groups at `+0x49c`…`+0x4c3` | Yes | **High CF** |
| Clear flags `+0x488/+0x489/+0x48a` area + 6-iter dual-zero loop | Yes | **High** |
| `this+0x498` (`[0x126]`) = -1 | Yes | **High** |
| Scale slot `[0x131] = DAT_00a0f734` (0.9) | Yes | **High** |
| Font/metrics `[0x8a]/[0x8b] = DAT_00d1e7b0/b4` | Yes | **High** |

---

## 5. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = button ctor | **High** | size/vtbl + button XML factories |
| Product class name | **Tentative** | CNDUIButton-class inferred |
| Color-byte semantics | **Tentative** | 0xFF likely “unset/default” ARGB channels |
| Runtime | **Open** | — |

---

## 6. Gaps

1. Exact product type name.
2. Mapping of each 0xFF group to hover/press/disabled states.
3. Decompiler `unaff_ESI` / `in_EAX` — sealed via base + callers, not formal params.
