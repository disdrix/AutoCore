# Review B (skeptical / adversarial): `Client_SendSectorPacket` @ `0x00807460`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (strengthen pass — interact/skill + expanded census) |
| **Counterpart** | `reviews/A_aa_00807460_Client_SendSectorPacket.md` |
| **Verdict** | **accept-with-gaps** on CF + residual seals; runtime still open |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Always reliable ordered | **Was Weak** — now **falsified as “always”**: flags depend on EAX bit 3. **But** skill + interact + large census force `EAX=8` → flags **0** (GuaranteedOrdered). Effective C2S path is ordered. |
| 2 | Encrypts payload here | **Falsified** — passthrough to conn vtbl+0x18 |
| 3 | DAT_00d1a840 is this | **Often** used as global client (`MOV ECX, 0xd1a840`) — body is pure thiscall on ECX; interact does use global; skill uses live client in EDI/EAX |
| 4 | `in_EAX` is decompiler garbage | **Falsified** — live-in EAX consumed by SHR/NOT/AND; callers deliberately set bit3 (lit 8 or gated EBP) |
| 5 | Null conn is a bug | **Falsified** — intentional early-out, shared with sibling inlines |
| 6 | flags=2 is Guaranteed (unordered) | **Falsified as value 1** — domain is {0,2}; 2 matches TNL **RPCUnguaranteed**, not RPCGuaranteed=1 (`RPCEvent.cs`) |
| 7 | All 67 xrefs proven EAX=8 | **Weakened** — skill/interact High; census High; rare UI site `0x0086d0d1` (opcode 0x20c6) has no local `MOV EAX,8` in ±16 insn — do **not** claim 100% exhaustiveness |
| — | Param names / types production-ready | **Overstated** for connection type name / vtbl method name |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Connection object at client+0xc78 | High | Wrong → no send / wrong object |
| Send vtable slot +0x18 | High | Wrong → protocol path fail |
| size is signed short promoted | High | Truncation / wrong length |
| Flag algebra + skill/interact EAX=8 → 0 | High | Wrong guarantee class on wire for cast/pick |
| TNL 0/2 enum names | High | Misname only if custom AA enum reuses values differently |
| Always returns 0 | High | Callers cannot detect drop |
| Clean is CF-preserving scaffold | High | Low for map use |
| Universal 67-site bit3 | Probable | One rare UI path might send Unguaranteed if EAX bit3 clear |

---

## 3. Surviving contract for AutoCore

```
Client_SendSectorPacket(client, size16, buf) -> 0
  // register: EAX = sendModeBits; bit3 set (value 8) → GuaranteedOrdered
  if conn = *(client+0xc78):
    conn->vtbl[+0x18]( -1, buf, (int)size16, (EAX&8) ? 0 : 2 )
  // null conn: silent drop, still returns 0

Skill:   Client_RequestCastSkill @ 0x00941883 — EAX:=8, size 0x28, opcode 0x2030
Interact: Client_InteractClickPickTarget @ 0x00924fc0 — EAX:=8, size 0x10, this=DAT_00d1a840
Canonical sampled sites: EAX:=8 (or EBP under CMP EBP,8) before CALL → flags:=0
```

Matches AutoCore `TNLConnection.SendGamePacket(..., RPCGuaranteedOrdered)` default for game packets.

---

## 4. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Exact meaning of `~(EAX>>2)&2` | **Sealed High** — {0=GuaranteedOrdered, 2=Unguaranteed}; bit3 of EAX selects; TNL enum in-repo |
| Null conn silent drop | **Sealed High** — intentional |
| Skill + interact EAX contract | **Sealed High** — live asm |
| Runtime / bit-exact | Still open |
| client+0xc78 ≡ DAT_00d1b4b8 | Open (out of unit) |
| Exhaustive 67-xref bit3 | Open / Probable (not skill/interact) |

**Verdict:** **accept-with-gaps** — safe as behavioral map for AutoCore C2S transport for **interact and skill** under the `EAX=8` contract; treat wrapper as GuaranteedOrdered passthrough for those paths and the large ordered-census majority.
