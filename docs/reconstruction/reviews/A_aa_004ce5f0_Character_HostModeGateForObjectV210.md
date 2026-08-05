# Review A (reconstruction fidelity): `aa_004ce5f0` Character_HostModeGateForObjectV210

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5f0` |
| **VA** | `0x004ce5f0`–`0x004ce632` |
| **Canonical name** | `Character_HostModeGateForObjectV210` |
| **Prior / alias** | `FUN_004ce5f0`; parent-seed `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0` (**incomplete**) |
| **Review date** | `2026-07-29` (W19-F OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| **System** | inventory-transfer / equip / hardpoint gates |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf gate:** given host + object, return whether object’s **vtbl+0x210(0)** is non-null **and** host mode flags (`+0xf5` or `+0x7e`) allow the operation. Multi-caller equip/hardpoint helper — not confirm-UI exclusive.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.md` (+ W19-F append) |
| Annotated | `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_HostModeGateForObjectV210.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004ce5f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| Live decompile | ≡ raw |
| Live bytes | full body hex; three `c2 04 00`; `cc` pad |

---

## 3. Byte seal — **SEALED**

| Claim | Evidence | Conf |
|---|---|---|
| ECX = host | `mov esi, ecx` | **High** |
| stack arg0 = object | `mov eax, [esp+4]` | **High** |
| `ret 4` | three `c2 04 00` | **High** |
| MI adjust | `lea ecx, [edx+eax+4]` | **High** |
| vcall slot `0x210` arg `0` | `push 0; call [eax+0x210]` | **High** |
| Host flags `+0xf5`, `+0x7e` | `cmp [esi+0xf5]`; `cmp [esi+0x7e]` + `setne` | **High** |
| Leaf (no CALL imm) | only indirect call | **High** |
| Decompile ≡ raw ≡ bytes | three-rep | **High** |

```c
bool __thiscall Character_HostModeGateForObjectV210(int host, int object);
// ret 4
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| null object → false | **Yes** |
| vcall null → false | **Yes** |
| `+0xf5` short-circuit true | **Yes** |
| else `+0x7e != 0` | **Yes** |
| No invented stores / callees | **Yes** |

---

## 5. Caller roles (xref, not body)

| Site | Role note |
|---|---|
| `Character_TryEquipItem` type 0xe | false → equip code **1** |
| `FUN_004f6890` (type 0x10 equip helper) | false → **1** |
| `Client_SendInventoryDrop_Hardpoint` ×2 | hardpoint drop gate |
| `FUN_00941b20` | confirm/customize path |
| `FUN_004f6a80` | equip-family helper |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf gate CF | **High** | full byte seal |
| thiscall + ret 4 | **High** | |
| Multi-caller (not confirm-only) | **High** | 6 CODE xrefs |
| Host flag product English | **Open** | offsets sealed |
| Vfunc+0x210 product English | **Open** | slot sealed; name not |
| PDB symbol | **Open** | |

---

## 7. Gaps / open

1. Product names for host `+0xf5` / `+0x7e` on this class.
2. Product name for object `vtbl+0x210` with arg 0.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
