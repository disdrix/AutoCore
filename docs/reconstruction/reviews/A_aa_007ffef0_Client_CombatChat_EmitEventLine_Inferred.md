# Review A (reconstruction fidelity): `aa_007ffef0` Client_CombatChat_EmitEventLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffef0` |
| **VA** | `0x007ffef0`–`0x00800ad1` exclusive |
| **Body size** | **3041 B** (`0xBE1`) |
| **Canonical name** | `Client_CombatChat_EmitEventLine_Inferred` |
| **Ghidra name** | `FUN_007ffef0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007ffef0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| **System** | combat chat UI / skills residual consumer |
| **Agent** | WQ9D-I OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/channels/strings/caller sealed; product event type + option-global English open |

---

## 1. Purpose

**Client combat-chat formatter + sink.** Given a client host and a combat-event blob, resolve actor/target names, apply relevance/crew filters, `sprintf` a localized line from embedded English plates, and call `CDlgChatLog_AppendChannelMessage` with channel codes **`0x10`–`0x16`**. Not damage application, not cast validate.

```c
// two stack args, ret 8
void Client_CombatChat_EmitEventLine_Inferred(ClientHost* host, void* combatEvent);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` @ `0x007ffef0` |
| Bounds / epilogue | `get_function_by_address`; `read_memory` @ entry + `0x00800ac0` → `C2 08 00` |
| Callers / xrefs | 1 caller `FUN_0093ffb0` @ `0x00940e37` |
| Callees | TFID helpers, `FUN_0040aff0`, `FUN_005749d0`, locale/string pool, `FUN_008f8200` |
| Constants | `read_memory` null TFID, `"for"`/`"Hits"`/`"Saps"`/`"XP"`/`""` |
| Raw / annotated / clean | trio under `docs/reconstruction/` |
| Peer duals | `CDlgChatLog_AppendChannelMessage`, `Object_CopyTfid16At228_Inferred`, `VehicleCrew_ContainsMember_Inferred` |

**Not performed:** Launcher, runtime golden, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x007ffef0`–`0x00800ad1` excl. | **Confirmed** | function meta |
| `ret 8` / two stack args | **Confirmed** | epilogue bytes `C2 08 00` |
| Live decompile ≡ raw CF | **Confirmed** | 2026-08-04 re-verify |
| Role: combat chat emit (not sim) | **Confirmed** | strings + `FUN_008f8200` only sink |
| Channel codes 0x10–0x16 | **Confirmed** | decompile immediates |
| Type switch 0..3 (dmg/repair/power/XP) | **Confirmed** | switch + `"XP"` @ `DAT_00a43258` |
| Flag family dodge/resist/deflect/crit | **Confirmed** | string plates |
| Null TFID `DAT_00a1e850` | **Confirmed** | `read_memory` |
| Empty style `DAT_00a1419b` | **Confirmed** | first byte 0; peer chat dual |
| Single caller `FUN_0093ffb0` | **Confirmed** | callers/xrefs |
| Product C++ name | **Inferred** | no RTTI/PDB on VA |
| Event struct product layout | **High structural / open English** | decompiler TFID overlay |
| `DAT_00af921c` product meaning | **Open** | bits used; also month-table label elsewhere |

---

## 4. Control flow (high level)

```
gates: host+0xF40, DAT_00d1b644, event!=null
optional: suppress self-dodge when TFIDs match local + dodge flag
locale init; zero msg / nameTarget / nameSource buffers
resolve target (event+16) + source (event+0)
bLocalTarget / bLocalSource via vtbl+0x210 vs host+0xE98
related-object path (vtbl+0x1D8 → TFID copy → crew/bits) → bRelated
if !any relevance: require localVeh+0xCB0 and crew membership on target or source
resolve display names; require nameTarget non-empty
switch eventType:
  0 damage family / 1 repair / 2 power / 3 XP
if msg non-empty && CDlgChatLog host: AppendChannelMessage(channel, "", msg, gm=0)
```

---

## 5. Gaps (acceptable)

1. Product/PDB demangle.
2. Full product struct for combat event (offsets sealed via decompiler fields).
3. English for `+0xF40` / `DAT_00d1b644`.
4. Confirm `DAT_00af921c` options vs month-name symbol collision.
5. Runtime / bit-exact / differential (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.
