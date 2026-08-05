# Review B (skeptical / adversarial): `aa_008120d0` Client_CreateObjectFromCbidPacket_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008120d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-L) |
| **Counterpart** | `reviews/A_aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_008120d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is sector-**update** | **Falsified** — factory allocate; twin `00811e00` is update with ProcessSectorUpdate string |
| 2 | thiscall with ECX=game | **Falsified** — both args stack; no ECX this at entry |
| 3 | cdecl caller cleans | **Falsified** — `RET 8` callee cleans |
| 4 | Always succeeds | **Falsified** — null factory → log + return 0 |
| 5 | Mode arg is always 1 | **Falsified** — push/imm **2** into `vtbl+0xc4` |
| 6 | Decompile is complete byte CF | **Partial** — `FUN_0092a3b0` in callees/bytes; decompiler "unreachable" warnings |
| 7 | Same as simpler `AllocateNewObjectFromCbid` helper | **Falsified** — full packet apply + post helpers, not just factory |
| 8 | Product name is plate-exact method | **Overstated** — plate is fail message only; `_Inferred` required |
| 9 | Returns void | **Falsified** — EAX = object* (`MOV EAX,EDI` success) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Create vs update role | **High** | wrong net path |
| RET 8 + 2 stack args | **High** | ABI break |
| Factory CBID + fail string | **High** | miss create failures |
| mode=2 create apply | **High** | wrong vfunc contract |
| Packet flag offsets | **High** | wrong state fuse |
| `0092a3b0` residual | **Medium** | miss HB-list side effect |
| Product English | **Medium** | naming only |
| Runtime wire | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,8; save EBX/EBP/EDI
obj = GiveItemByCbid([packet+4])
if null: log; XOR EAX,EAX; RET 8
vtbl+8; vtbl+0x1cc; flag fuse; vtbl+0xc4(...,2,...)
optional 009972a0+008024d0; optional 007fb2b0
MOV EAX,EDI; restore; RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for primary stages. Callers pass `(game, packet)` from resolve-miss branches.

---

## 4. Surviving contract for AutoCore

```
// Client create only — do not use as ProcessSectorUpdate (00811e00).
// On resolve miss (0x201C / siblings): obj = Client_CreateObjectFromCbidPacket_Inferred(game, pkt)
// Preserve mode=2 into vtbl+0xc4 and packet flag offsets (+0xa0..+0xa8, +0xc0, mask +8/+c).
// Treat FUN_0092a3b0 multi-flag path as residual until bytes dualed fully.
```

---

## 5. Verdict

Adversarial pass **confirms** A on sealed create CF/ABI; residual `0092a3b0` + product English keep verdict at **accept-with-gaps**.
