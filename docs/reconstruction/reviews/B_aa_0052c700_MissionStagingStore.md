# Review B (skeptical / adversarial): `aa_0052c700` Mission staging map store

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052c700` |
| **VA** | `0x0052c700` |
| **Canonical name** | `FUN_0052c700` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_0052c700_MissionStagingStore.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on shape; **reject** any pure-eligibility or product-name claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Mission eligibility checker” | **Falsified** — only map upsert; no race/level/prereq reads |
| “GiveMission itself” | **Falsified** — Prerequisites **calls this then** `CVOGReaction_GiveMission` |
| “Dialog UI builder” | **Falsified** — only stages; Show is separate |
| “Always stores 8 COIDs” | **Falsified** — award path stores 8×`−1` + NPC/AutoAssign |
| “`void` return” | **Falsified by asm** — `EAX = node+0x18` consumed by `FUN_0052dac0` |
| “Map root is only `+0x50c`” | **Partial** — `+0x50c` is **end sentinel**; map **object** is `+0x508` |
| “dword[10] caller-authoritative” | **Falsified** — body **always** writes key over payload `+0x28` |
| Product name `PrepareMissionAward` (`MISSION_SYSTEM.md`) | **Unproven** — no string; role is broader than award (dialog offers too) |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `FUN_00538a40(local_40,&param_2)` missing map `this` | Asm: `LEA EBX,[char+0x508]; MOV ECX,EBX` |
| `void` return | Asm leaves `EAX = payload*` |
| `*(node+0x40) = key` only | Equivalent to `payload[+0x28]`; same store |
| Second lower_bound out-param mess (`&param_3`) | Re-find after insert; then payload write — CF holds |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Are COIDs really 8×i32 not 4×TFID? | Packet path copies **8** dwords; clear walks **4 pairs** with ResolveObjectTarget(lo,hi) — both views compatible if each “item” is one i32 COID (resolve may pack differently). Slot **count 8** sealed; TFID-pair English **not** sealed. | High count / Probable pair meaning |
| Is `[8]` always NPC? | Only Prerequisites fill from `def+0x88`; dialog leaves `−1`. **Field slot** sealed; universal NPC meaning **only on award path**. | High |
| Is `[9]` AutoAssign? | Same: award path from `def+0xfc` (`Mission.AutoAssign`); dialog `−1`. | High on award path |
| Is map `std::map` exactly? | MSVC RB shape (left/parent/right, isnil `+0x49`, insert/lower_bound) — **High** structural; STL product typedef open. | High shape |

---

## 4. Surviving contract (minimal)

```
// thiscall Character*
u32* MissionStagingMap_Upsert(Character* ch, u32 missionKey, const u32 payload[12]);
// map @ ch+0x508; end @ ch+0x50c; count @ ch+0x510 (sibling)
// node.key @ +0x10; node.payload @ +0x18 (12 dwords)
// ALWAYS: payload[10] = missionKey after return
// RETURNS: &node.payload[0]
```

Do **not** treat as:
- eligibility API
- sole “pending mission” structure (active missions live elsewhere, e.g. `+0x540`)
- named product API without strings

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| 12-dword sealed | **Agree** — asm `ECX=0xC` |
| Map `+0x508` / end `+0x50c` | **Agree** |
| Force key @ `+0x28` | **Agree** |
| Dialog vs award fills | **Agree** with path-qualified semantics |
| Product English open | **Agree** — keep open |
| COID required vs reward | **Agree open** — out of OWN |

---

## 6. Residual (honest)

1. Product / export name.
2. Payload `[11]` flag taxonomy.
3. Whether staging map is exclusively “dialog offers” vs shared “pending grant scratch” (callers prove **shared multi-use**).
4. 4-byte gap `node+0x14` between key and payload.
5. Runtime observation of map size / multi-offer dialog.

---

## 7. Verdict

### **accept-with-gaps**

Shape, offsets, copy width, forced key, and return pointer are **sealed**. Reject broader product naming and single-purpose English. Dual A’s layout table is acceptable if path-qualified (dialog vs award) and product name remains open.
