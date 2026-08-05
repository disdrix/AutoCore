# Review A (reconstruction fidelity): `aa_008f8200` CDlgChatLog_AppendChannelMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f8200` |
| **VA** | `0x008f8200` |
| **Canonical name (working)** | `CDlgChatLog_AppendChannelMessage` (was `FUN_008f8200`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008f8200_CDlgChatLog_AppendChannelMessage.md` |
| **System tag** | `skills-abilities` / chat UI (RequestCast failure toast path) |
| **Verdict** | **accept-with-gaps** (signature, channel gates, dual-pane, file-log names sealed; product type fields open) |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008f8200_FUN_008f8200.md` |
| Annotated | `docs/reconstruction/raw/aa_008f8200_FUN_008f8200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008f8200.cpp` |
| Function record | `docs/reconstruction/functions/aa_008f8200_FUN_008f8200.md` |
| RequestCast caller | `Client_RequestCastSkill` @ `0x00941590` → `FUN_008f8200(DAT_00d1b8dc, 0x18, &DAT_00a156cc, failMsg, 0)` |
| Sibling toast callers | `Client_CastBlockFeedback`, `Client_Skill_ResolveCastTarget`, `Client_RecvSkillStatusEffect` |
| Host cast | `Client_RecvBroadcast` RTDynamicCast → `CDlgChatLog` then this unit |

**Live re-decompile + force_decompile + read_memory + get_assembly_context + callees performed 2026-07-29 (OWN VA only).**

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: chat-log channel append / toast sink | **Confirmed** | RTTI host `CDlgChatLog`; strings `chat_log.txt` / `chat_log_combat.txt`; ring + UI refresh |
| Formals: `(pChatLog, nChannel, pszStyle, pszText, bGmPrefix)` | **High** | 5 stack args; asm loads map 1:1 |
| Channel clamp: `<0` or `>0x18` → `0` | **Confirmed** | `CMP EBP,0x19` / `TEST EBP` → `XOR EBP,EBP` |
| Channel enable mask `DAT_00af9218 & (1<<channel)` | **Confirmed** | early ret if bit clear |
| Image snapshot mask all-ones (`0xffffffff`) | **Confirmed** | `read_memory 0x00af9218` |
| `bGmPrefix==0` → empty style prefix `DAT_00a1419b` (`""`) | **Confirmed** | `read_memory` first byte `0x00` |
| `bGmPrefix!=0` → `"(GM)"` @ `0x00a36c9c` | **Confirmed** | `read_memory` `28 47 4d 29 00` |
| Style+prefix buffer `local_18` via `_snprintf("%s%s",…)` format `0x00a36c94` | **Confirmed** | format bytes `%s%s\0` |
| Ignore-list gate: `thiscall FUN_00573af0(DAT_00d1da2c, pszStyle)`; nonzero → suppress | **Confirmed** | asm `MOV ECX,[0x00d1da2c]; PUSH ESI; CALL 0x00573af0` |
| Heap copy of `pszText` then optional profanity filter `FUN_0079d560` when globals set | **High** | CF + callee body masks with `****` |
| File log: EAX=`chat_log.txt` (`0x00a36c84`) or `chat_log_combat.txt` (`0x00a36c70`); EBX=`local_18` | **Confirmed** | asm sole DATA xrefs from this fn; decompiler omits EAX/EBX setup |
| Dual pane: channel ∈ `[0x10,0x18]` → `host+0x544`; else `host+0x540` | **Confirmed** | `MOV EBX,[EAX+EDX*4+0x540]` |
| Ring capacity `0x96` (150); wrap sets byte `+0x500` | **Confirmed** | `CMP EAX,0x96` |
| Slot store via `FUN_0095ab00` into entry at base `+0x520 + idx*0x10` style | **High** | asm `ADD ESI,0x52; SHL ESI,4` relative ring |
| Visible refresh: vtbl `+0x3d8` then `FUN_008f7cf0` / `FUN_008f62a0` / `FUN_008f6100(1)` | **High** | CF match |
| Channel `2` copies `pszStyle` into `DAT_00d1b978+0x924` | **High** | CF only; product role open |
| RequestCast fail path uses channel **`0x18`**, style **`&DAT_00a156cc` (`"!"`)**, text failMsg, gm=0 | **Confirmed** | caller clean + `read_memory 0x00a156cc` = `21 00 00 00` |
| Not skill-cast logic itself | **Confirmed** | pure UI/log sink; no packet send |

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Channel clamp + enable mask early out | **Yes** |
| GM vs empty prefix + snprintf style buffer | **Yes** |
| Ignore-list early out | **Yes** (this recovery needs asm for `ECX`) |
| Heap copy text | **Yes** |
| Optional `FUN_0079d560` | **Yes** |
| File-log gate (`DAT_00d1775c` bytes) + `FUN_008f6800` | **Yes** (filename/prefix via registers sealed in asm) |
| Dual pane + ring + optional UI rebuild | **Yes** |
| Channel-2 style stash | **Yes** |
| `operator_delete[]` + return | **Yes** |
| Live force_decompile 2026-07-29 ≡ frozen raw body | **Yes** |

---

## 4. Sealed string / constant plate

| Literal / constant | VA | Bytes / value | Owner in this fn |
|---|---|---|---|
| `chat_log_combat.txt` | `0x00a36c70` | ascii | sole DATA xref `0x008f82e1` |
| `chat_log.txt` | `0x00a36c84` | ascii | sole DATA xref `0x008f82cc` |
| `"%s%s"` | `0x00a36c94` | `25 73 25 73 00` | snprintf format |
| `"(GM)"` | `0x00a36c9c` | `28 47 4d 29 00` | GM prefix |
| empty prefix | `0x00a1419b` | first byte `00` | non-GM |
| `"!"` (style at many toast sites) | `0x00a156cc` | `21 00 00 00` | **not** owned here; caller-supplied style |
| Channel max | — | `0x18` (24) | clamp + combat-range high |
| Combat/special range | — | `0x10`..`0x18` | file name + pane index 1 |
| Ring size | — | `0x96` (150) | wrap |

---

## 5. RequestCast-path contract (this unit only)

```
// Failure toast after LocalCastValidate reject (and siblings):
if (DAT_00d1b8dc != 0) {
  CDlgChatLog_AppendChannelMessage(
      DAT_00d1b8dc,   // CDlgChatLog* host (global)
      0x18,           // channel — combat/special pane (+0x544)
      &DAT_00a156cc,  // style "!"
      failMsg,        // formatted failure text
      0);             // non-GM prefix
}
```

Behavior for that call:

1. Channel `0x18` in range → keep.
2. Enable bit 24 in `DAT_00af9218` must be set (image default all-on).
3. Ignore list must **not** contain style `"!"` (else silent drop).
4. Heap-copy `failMsg`; optional censor.
5. File append path may use **`chat_log_combat.txt`** (channel ≥ 0x10).
6. UI append into **`host+0x544`** combat log pane ring; refresh if visible.

---

## 6. Gaps / open questions

1. Product type for chat-log pane object at `host+0x540/+0x544` (fields `+0x500`..`+0x51c` ring).
2. Full product meaning of each channel id `0`..`0x18` (only bounds + combat split sealed).
3. Identity/product of ignore list object `DAT_00d1da2c` / `FUN_00573af0`.
4. File-log enable pair in `_DAT_00d1775c` (two flag bytes) product names.
5. Channel-2 → `DAT_00d1b978+0x924` product (last-style stash?).
6. Runtime capture of toast + file line for a cast fail.

**Verdict:** Dual-pane chat append sink **sealed** for RequestCast toast use. Prefer working name `CDlgChatLog_AppendChannelMessage`. Do not treat this as cast validation.
