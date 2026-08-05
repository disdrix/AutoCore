# Review A (reconstruction fidelity): `aa_00814400` Client_RecvObjectResolveWeaponReset_0x201c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00814400` |
| **VA** | `0x00814400`–`0x00814466` |
| **Canonical name** | `Client_RecvObjectResolveWeaponReset_0x201c_Inferred` |
| **Ghidra symbol** | `FUN_00814400` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| **System** | client net / combat weapon state |
| **Wire** | S2C **`0x201C`** |
| **Verdict** | **accept-with-gaps** — opcode + resolve/create + weapon clear/suppress FireHelper sealed; product packet English open |

**Tools:** Ghidra `decompile_function` + `read_memory` body + parent `Client_PacketDispatch` decompile + callers/xrefs. No `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

S2C **0x201C** packet handler that:

1. **Resolves** a world object from packet identity fields (`+0x90`, `+0x94`, type byte `+0x98`) using `CVOGReaction_ResolveObjectTarget` with host `*(game+0xD34)`.
2. **Creates** the object if missing (`FUN_008120d0`), else runs **sector-update** (`FUN_00811e00`).
3. If the object exposes a weapon via **`vtbl+0x1E0`**, **clears fire flags** and runs **`Weapon_FireHelper(..., suppressFire=1)`** — state refresh **without** primary fire emit.

Distinct from sibling `0x201A` (`FUN_00814470`) which only resolve/creates without the weapon-reset tail.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00814400_FUN_00814400.md` (+ W24-Q append) |
| Annotated | `docs/reconstruction/raw/aa_00814400_FUN_00814400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvObjectResolveWeaponReset_0x201c_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00814400.cpp` |
| Function record | `docs/reconstruction/functions/aa_00814400_Client_RecvObjectResolveWeaponReset_0x201c_Inferred.md` |
| Live decompile | Ghidra `0x00814400` — **≡** raw body |
| Live bytes | `read_memory` len 128 @ entry |
| Parent | `Client_PacketDispatch` case `0x201C` → `FUN_00814400()` |
| Sibling duals | `Weapon_SetFireFlagPair`, `Weapon_FireHelper` (suppress path) |

---

## 3. Sealed residuals

### 3.1 Dispatch ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Opcode | **`0x201C`** sole xref from `Client_PacketDispatch` |
| EDI | packet body* (`[edi+0x90/0x94/0x98]`) |
| EBX | game/ctx* (`[ebx+0xD34]` resolver host) |
| Epilogue | `pop esi; ret` |
| Body | 102 B (`0x00814400`–`0x00814466`) |

### 3.2 Resolve / create / update — **SEALED**

| Fact | Evidence |
|---|---|
| Resolve args | type `+0x98`, ids `+0x90`/`+0x94`, this=`*(ebx+0xD34)` |
| Null → create | `FUN_008120d0(ebx, edi)` returns object* |
| Non-null → update | `FUN_00811e00` with ECX=edi, stack ebx; object remains in EAX/`in_EAX` |

### 3.3 Weapon tail — **SEALED**

| Fact | Evidence |
|---|---|
| Getter | `call [obj.vtbl+0x1E0]` |
| Clear | `Weapon_SetFireFlagPair(w, 0)` |
| Helper | `Weapon_FireHelper(w, &DAT_00d1a680, 1)` — **suppress=1** |

### 3.4 Name — **INFERRED**

`Client_RecvObjectResolveWeaponReset_0x201c_Inferred` — role from opcode + CF. Product English open.

---

## 4. Confidence table

| Claim | Confidence |
|---|---|
| Bytes / CF / opcode | **High** |
| Packet field offsets for resolve | **High** |
| Create-or-update branch | **High** |
| Weapon clear + suppress FireHelper | **High** |
| Product packet / vtbl English | **Medium** / open |
| Runtime wire | **Open** |

**Verdict:** **accept-with-gaps**
