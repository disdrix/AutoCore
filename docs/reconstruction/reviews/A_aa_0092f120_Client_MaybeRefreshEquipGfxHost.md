# Review A (reconstruction fidelity): `aa_0092f120` Client_MaybeRefreshEquipGfxHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f120` |
| **VA** | `0x0092f120` |
| **Canonical name** | `Client_MaybeRefreshEquipGfxHost` |
| **Prior names** | `FUN_0092f120`, `Named_CalleeOf_Client_RecvInventoryEquip_0092f120` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0092f120_Client_MaybeRefreshEquipGfxHost.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tiny client helper:** if `client+0xE04` is non-null **and** `*(client+0xE04 + 0xE898)` is non-null, **tail-call** `FUN_004962b0` with that inner pointer as `ECX`.

Body (bytes-sealed):

```
// EAX = client (VOGClient*)
mov  eax, [eax+0xE04]
test eax, eax
jz   ret
mov  eax, [eax+0xE898]
test eax, eax
jz   ret
mov  ecx, eax
jmp  FUN_004962b0      // tail call (__fastcall ECX)
; ret (fallthrough path)
```

**Calling convention:** `EAX` = client. No stack args.

**Callee `FUN_004962b0`:** if `*(char*)(host+0x53) != 0` then `FUN_004367f0(0,0)` (resource/FX unload-or-refresh). Else no-op.

**Side effects:** optional graphics/FX host refresh only. **No** inventory / equip / network.

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092f120_FUN_0092f120.md` |
| Annotated | `docs/reconstruction/raw/aa_0092f120_FUN_0092f120.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0092f120.cpp` |
| Function record | `docs/reconstruction/functions/aa_0092f120_FUN_0092f120.md` |
| Live re-decompile | Ghidra MCP ≡ raw |
| Bytes | `8B 80 04 0E 00 00 85 C0 74 11 8B 80 98 E8 00 00 85 C0 74 07 8B C8 E9 … C3` |
| Callee | `FUN_004962b0` @ `0x004962b0` |
| Callers | `Client_RecvInventoryEquip` @ `0x008143b8` (`mov eax,esi; call`); `Client_RecvInventoryUnequipNotify` @ `0x00813ef2` |
| Parallel pattern | `VOGClient_CompletelyDestroyObject` tail uses `client[0x381]`≡`+0xE04` then `+0xE898` → same `FUN_004962b0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime; full identity of `+0xE04` object.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `client+0xE04` | **Yes** |
| Null → return | **Yes** |
| Load `host+0xE898` | **Yes** |
| Null → return | **Yes** |
| Tail `jmp FUN_004962b0` with ECX=host | **Yes** (not nested call+ret) |

### 3.1 Offset seal

| Offset | Role | Evidence |
|--------|------|----------|
| client `+0xE04` (`[0x381]`) | intermediate host / subsystem | bytes; destroy-object parallel |
| host `+0xE898` | gfx/FX object passed to `FUN_004962b0` | bytes |
| gfx `+0x53` | enable gate inside callee | `FUN_004962b0` body |

---

## 4. Naming

| Claim | Confidence |
|---|---|
| Post-equip/unequip optional gfx host refresh | **High** (callers + parallel destroy tail) |
| Canonical `Client_MaybeRefreshEquipGfxHost` | **Probable / Inferred** |
| Exact product subsystem at `+0xE04` | **Open** |

---

## 5. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** |
| Dual null gate + tail call | **High / Sealed** |
| Caller context equip/unequip | **High** |
| Callee flag@`+0x53` → `FUN_004367f0` | **High** |
| Semantic name of gfx host | **Open / Tentative** |
| Runtime | **Open** |
| Overall | **accept-with-gaps** |

## 6. Gaps

- Type of `client+0xE04` and `+0xE898` objects
- Exact behavior of `FUN_004367f0(0,0)` (asset unload vs mesh refresh)
- Whether other non-inventory callers exist (xrefs show 2 only)
