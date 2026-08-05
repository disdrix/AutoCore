# Review A (reconstruction fidelity): `aa_007f5120` Input_KeyCodeToDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f5120` |
| **VA** | `0x007f5120`–`0x007f5d9c` |
| **Canonical name** | `Input_KeyCodeToDisplayName` |
| **Ghidra name** | `FUN_007f5120` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ7R-G) |
| **Counterpart** | `reviews/B_aa_007f5120_Input_KeyCodeToDisplayName.md` |
| **System** | input-drive-control / UI keybind display |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Map a 16-bit input key/button code (DIK, mouse `0xF00+`, joystick synthetic ranges) to a NUL-terminated display name for keybind UI. Returns pointer into a static work buffer or snprintf scratch (or empty string).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f5120_FUN_007f5120.md` (+ 2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_007f5120_FUN_007f5120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Input_KeyCodeToDisplayName.cpp` |
| Function record | `docs/reconstruction/functions/aa_007f5120_Input_KeyCodeToDisplayName.md` |
| Live | decompile; entry `0F B7 C2`; strings `MOUSE1`/`ESCAPE`/`Joy_*`; empty `@0x00a1419b` |

---

## 3. Signature (sealed)

```c
// DX = keyCode u16; EAX = const char* name (static / scratch / empty)
const char* Input_KeyCodeToDisplayName(uint16_t keyCode /* DX */);
```

| Formal | Source | Conf |
|---|---|---|
| keyCode | **DX** (`MOVZX EAX,DX`) | **High** |
| return | **EAX** ptr to C string | **High** |
| callees | `_snprintf` only | **High** |

---

## 4. Control flow (clean ≡ raw)

```
clear DAT_00d1f73c[0]
if code in mouse 0xF00..0xF07: copy MOUSE* label → buf; ret buf
switch DIK cases → named strings or single-letter ASCII into buf
if buf non-empty: ret &DAT_00d1f73c
if code < 0xF000: ret empty DAT_00a1419b
if code > 0xF1FF: snprintf Joy_POV… → DAT_00d1f0f8
if code < 0xF100: snprintf Joy_Button%03d
else: snprintf Joy_Axis…
ret scratch
```

| Stage | Match | Conf |
|---|---|---|
| DX formal + clear static | **Yes** | **High** |
| Mouse / DIK / Joy ranges | **Yes** | **High** |
| Empty fallback | **Yes** | **High** |
| Leaf of logic (only snprintf) | **Yes** | **High** |

---

## 5. Verdict

CF, ABI, range partition, and key string family sealed from decompile + memory. **accept**.
