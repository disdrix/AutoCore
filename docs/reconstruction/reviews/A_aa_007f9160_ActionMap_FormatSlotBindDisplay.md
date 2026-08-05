# Review A (reconstruction fidelity): `aa_007f9160` ActionMap_FormatSlotBindDisplay

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9160` |
| **VA** | `0x007f9160`–`0x007f9227` |
| **Canonical name** | `ActionMap_FormatSlotBindDisplay` |
| **Ghidra name** | `FUN_007f9160` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ7R-G) |
| **Counterpart** | `reviews/B_aa_007f9160_ActionMap_FormatSlotBindDisplay.md` |
| **System** | input-drive-control / UI keybind display |
| **Evidence pass** | Live decompile + complete analysis + **entry/body `read_memory`** (ABI); callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Format an ActionMap slot’s primary or alt bind into a caller-supplied C string: optional modifier name, `+`, key name. Used by interact prompts, attack HUD labels, tooltips, and mission-journal `[$…]` expansion.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f9160_FUN_007f9160.md` (+ 2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_007f9160_FUN_007f9160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_FormatSlotBindDisplay.cpp` |
| Related | `ActionMap_TrySetSlotBind` `0x007f72e0`; GetSlot `FUN_007f7240` |
| Live | body bytes: `PUSH EAX` base into GetSlot; `CMP [ESP+0xC],0` lane; `MOV EDX,EAX`/`ESI` before name calls; `RET 8` |

---

## 3. Signature (sealed)

```c
// EAX=ActionMap*  ECX=out  EDX=mode
// stack0=slotIndex  stack1=lane(0 primary / nonzero alt)
// AL success; RET 8
uint8_t ActionMap_FormatSlotBindDisplay(
    char* outBuf,           // ECX
    uint8_t slotIndex,      // stack0 → AL for GetSlot
    uint8_t lane,           // stack1
    void* actionMap,        // EAX
    uint32_t mode);         // EDX 0..3
```

| Formal | Source | Conf |
|---|---|---|
| outBuf | **ECX** → EBX | **High** |
| actionMap base | **EAX** pushed for GetSlot | **High** |
| mode | **EDX** through to GetSlot | **High** |
| slotIndex | stack0 | **High** |
| lane | stack1 (`0` primary) | **High** |
| return | AL; **RET 8** | **High** |

---

## 4. Control flow (bytes ≡ sealed)

```
slot = GetSlotPtr(base, mode, index)   // FUN_007f7240; ptr @ primary key field
if !slot || !out: AL=0; ret 8
*out = 0
if lane==0: key=*(u16*)slot;     mod=*(u16*)(slot+0x2A)
else:       key=*(u16*)(slot+2); mod=*(u16*)(slot+0x2C)
if key==0 && mod==0: AL=0; ret 8
if key!=0 && mod==0: goto format_key_only
// mod present (and maybe key):
  append Input_KeyCodeToDisplayName(mod)
  append "+"
format_key_only:
  append Input_KeyCodeToDisplayName(key)
  AL=1; ret 8
```

| Stage | Match | Conf |
|---|---|---|
| GetSlot + null gates | **Yes** | **High** |
| Lane offsets 0/0x2A vs 2/0x2C | **Yes** | **High** |
| Display order mod then key | **Yes** (bytes `MOV EDX,EAX` first) | **High** |
| `+` from `DAT_00a2e620` | **Yes** | **High** |
| RET 8 | **Yes** | **High** |

---

## 5. Verdict

Decompiler under-reported base/mode/RET and name-arg registers; bytes seal full contract. **accept**.
