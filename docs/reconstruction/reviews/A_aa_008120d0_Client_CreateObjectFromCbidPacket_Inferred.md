# Review A (reconstruction fidelity): `aa_008120d0` Client_CreateObjectFromCbidPacket_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008120d0` |
| **VA** | `0x008120d0`–`0x008122de` |
| **Canonical name** | `Client_CreateObjectFromCbidPacket_Inferred` |
| **Ghidra name** | `FUN_008120d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-L) |
| **Counterpart** | `reviews/B_aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` |
| **System** | client net / object create |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers/twin |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **allocate-and-create** path for sector-style packets:

1. Factory `CVOGReaction_GiveItemByCbid(*(packet+4))`.
2. On fail: log `"allocatenewobjectfromcbid failed %d Get a programmer"`; return null.
3. On success: vtbl init (`+8`, `+0x1cc`), fuse packet flags into object state, `vtbl+0xc4(..., mode=2, ...)`.
4. Optional post-steps for `packet+0xa1` (table helper) and `packet+0xc0` (selection helper).
5. Return new object*.

Used when resolve-or-create handlers find no existing object (e.g. S2C `0x201C` via `FUN_00814400`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008120d0_FUN_008120d0.md` (+ 2026-07-29 W26-L append) |
| Annotated | `docs/reconstruction/raw/aa_008120d0_FUN_008120d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CreateObjectFromCbidPacket_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008120d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008120d0_FUN_008120d0.md` |
| Named record | `docs/reconstruction/functions/aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` |
| Live | decompile ≡ raw primary CF; body 526 B to pad; `RET 8` |
| Twin | `FUN_00811e00` decompile (ProcessSectorUpdate string) |
| Parent dual | `Client_RecvObjectResolveWeaponReset_0x201c` (null → this) |

---

## 3. Signature (sealed)

```c
// 2 stack formals; RET 8; EAX = object*|null
GameObject* Client_CreateObjectFromCbidPacket_Inferred(
    GameClient* game, void* packet);
```

| Formal | Source | Conf |
|---|---|---|
| game | Stack[0x4] (EBX in several dispatch callers) | **High** |
| packet | Stack[0x8] (EDI/ESI in wrappers) | **High** |
| return | EAX object* / 0 | **High** |
| cleanup | `ADD ESP,8; RET 8` | **High** |
| thiscall? | **No** — both formals on stack | **High** |

---

## 4. Control flow (primary)

```
obj = GiveItemByCbid(pkt+4)
if !obj:
  log fail; return 0
obj.vtbl+8(cbid, game+0xe04 host, 0)
obj.vtbl+0x1cc()
fuse bit0 flags → obj[0x61]
compute flag_u3 from mask + packet flags + host+0xf5
obj.vtbl+0xc4(pkt, 2, host, !pkt[0xa1], flag_u3, flag_u3)
if pkt[0xa1]: 009972a0; 008024d0(... obj ids ...)
// residual: optional 0092a3b0
if pkt[0xc0]: 007fb2b0(obj ids)
return obj
```

| Stage | Match | Conf |
|---|---|---|
| Factory + fail log | **Yes** | **High** |
| Init vfuncs + mode 2 apply | **Yes** | **High** |
| Flag fusion offsets | **Yes** | **High** |
| Post +0xa1 / +0xc0 | **Yes** | **High** |
| Body size / RET 8 | **Yes** | **High** |
| `0092a3b0` always in decompile | **No** — bytes residual | **Medium** |

---

## 5. Machine bytes (`read_memory`)

- Entry frame: `83 EC 08 53 … 55 … 57` (SUB ESP,8; push EBX/EBP/EDI).
- Fail epilogue sample: `33 C0 … C2 08 00`.
- Success epilogue: `8B C7 5F 5D 5B 83 C4 08 C2 08 00` then pad `CC CC` before `FUN_008122e0`.
- Exclusive end **`0x008122de`**, size **`0x20E` (526)**.

---

## 6. Gaps

- Product packet / method English.
- Exact product meaning of vtbl `+0xc4` mode 2.
- Reachability of `FUN_0092a3b0` block (decompiler "unreachable" vs xref/callee list).
- Nested helpers not OWN.
- Runtime wire create differential — open.

---

## 7. Verdict

Primary CF, ABI, factory fail path, create-from-packet mode 2, and caller role are sealed. Residual on optional `0092a3b0` and product English → **accept-with-gaps**.
