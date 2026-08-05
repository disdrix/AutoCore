# Review A (reconstruction fidelity): `aa_0080b100` Client_RecvFailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b100` |
| **VA** | `0x0080b100` |
| **Canonical name (claim)** | `Client_RecvFailMission` (Ghidra still `FUN_0080b100`) |
| **Review date** | `2026-07-29` (dual residual re-seal — UF-012 framing + full body image) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080b100_Client_RecvFailMission.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Scratch** | `tmp/a_0080b100.md` |
| **Verdict** | **accept-with-gaps** — S2C FailMission handler identity **High**; opcode + full register/body framing **sealed High**; secondary helpers **Tentative/Probable** |

---

## 1. Purpose

Client **S2C FailMission apply** for sector opcode **`0x20B2`**:

1. Require local character present at `game+0xe98` (ECX entry = client; saved to EDI).
2. `CVOGReaction_FailMission(character, missionId)` with `missionId` from packet `*(EAX+0x10)`; character in ECX. **Return value ignored.**
3. `FUN_005307e0` — thiscall on same character — end-quest / fail teardown drain (consumes ids pushed by FailMissionNotify).
4. Optional objective-hash lookup on `char+0x548` with key `*(*DAT_00d1ad10 + 0x10)`; if miss → `FUN_0092fd00()`.
5. Optional UI object at `game+0x107c`: if visible (`vtbl+0x3d8`), **tail jmp** `vtbl+0x448` refresh path.

Returns void. **Does not** send packets. **Does not** validate packet CharacterCoid (`+0x08/+0x0C` unread).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `batch_decompile` `0x0080b100`, `0x0052da30`, `0x005307e0` (2026-07-29 re-seal) |
| Image / call site | `read_memory` @ `0x00815d90` (32B), body @ `0x0080b100` (128B) |
| Xrefs / callers / callees | sole `From 00815d97 in Client_PacketDispatch`; callees FailMission / `FUN_005307e0` / `CNDHash_LookupByKey@005b0920` / `FUN_0092fd00` |
| Raw / clean | `raw/aa_0080b100_Client_RecvFailMission.md`, `reconstructed-exact/Client_RecvFailMission.cpp` |
| Function record | `functions/aa_0080b100_Client_RecvFailMission.md` |
| Packet dispatch | `reconstructed-exact/Client_PacketDispatch.cpp` `case 0x20b2` |
| Callee FailMission | `0x0052da30` — dual A/B (Notify → `char+0x560` vector; drain by `FUN_005307e0`) |
| Wire | `docs/missionHandler.md` / `GameOpcode.FailMission = 0x20B2` |
| Upstream C2S | `FUN_00911840` case `0x4e46` sends size `0x18` opcode `0x20b2` |

---

## 3. Rename claim: `Client_RecvFailMission`

| Evidence | Strength |
|---|---|
| `Client_PacketDispatch` `case 0x20b2` → only this callee | **High / Confirmed** (xref `0x00815d97`) |
| Immediate call `CVOGReaction_FailMission(*(pkt+0x10))` with character ECX | **High** (asm) |
| Opcode named FailMission in missionHandler / GameOpcode | **High** |
| Mission id offset `+0x10` asm-sealed (`MOV EDX,[EAX+0x10]`) | **High** |
| Sole caller is packet dispatch (not UI) | **High** |

**Rename recommendation:** accept `Client_RecvFailMission` as **High**-confidence product name (inferred; no retail export string).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Handler for S2C `0x20B2` | **High / Confirmed** | Sole xref + dispatch case + enum (**UF-012 sealed**) |
| Call framing: EAX=packet (ESI), ECX=client (EBP) | **High / Confirmed** | Image `8b c6 8b cd e8 64 53 ff ff` @ `0x00815d93` |
| Character gate `+0xe98` | **High** | Body `MOV ECX,[EDI+0xe98]; TEST ECX; JZ skip` |
| Mission id at packet `+0x10` | **High** | Only packet field read; asm not layout-only |
| FailMission then `FUN_005307e0` order | **High** | Explicit sequential calls |
| FailMission `this` = character at `+0xe98` | **High** | Explicit ECX load before CALL → `0x0052da30` |
| FailMission return ignored | **High** | No `TEST AL`; always runs end-quest helper |
| `FUN_005307e0` thiscall on character | **High** | Re-loads ECX from `[EDI+0xe98]` before CALL |
| EAX clobber: packet only until FailMission returns | **High** | `MOV EAX,[EDI+0xe98]` @ `0x0080b121` for objective probe |
| `FUN_005307e0` product name / full dual | **Probable** | Role = end-quest drain + "Failed" toast; dual unit open |
| `DAT_00d1ad10` load shape (pointer global → `+0x10` key) | **High (shape)** | `MOV ECX,[DAT]; MOV EDX,[ECX+0x10]` |
| `DAT_00d1ad10` object identity / product | **Tentative** | Secondary cleanup gate only |
| `FUN_0092fd00` on objective miss | **Tentative** | Shared post-mission helper elsewhere |
| UI `+0x107c` vtbl refresh | **High CF** | `CALL [vtbl+0x3d8]` then **`POP EDI; JMP [vtbl+0x448]`** |
| Local apply without server | **No** | This is the **recv** path; C2S is UI dispatch |

---

## 5. Control flow (live ≡ clean scaffold ≡ image)

| Stage | Match |
|---|---|
| Bail if no character `+0xe98` | **Yes** (`JZ 0x0080b173`) |
| FailMission(missionId from `+0x10`, this=char) | **Yes** (return discarded) |
| `FUN_005307e0(char)` | **Yes** |
| Re-check character in **EAX**; optional `CNDHash_LookupByKey(char+0x548, *(*DAT+0x10))` | **Yes** |
| Miss → `FUN_0092fd00` | **Yes** |
| Optional UI: predicate call then **tail jmp** `+0x448` | **Yes** (not nested call) |

No invented branches in clean scaffold. Secondary path does **not** re-read the packet.

---

## 6. Packet layout (cross-unit)

```
offset  field           notes
+0x00   opcode          0x20B2 (dispatch already switched)
+0x04   pad             missionState: +4 pad
+0x08   characterCoid   i64 (lo/hi) — C2S fills from char+0x164/0x168; **unread here**
+0x10   missionId       i32 — this handler reads here (asm)
+0x14   pad             size total 0x18
```

C2S builder (`0x4e46`) writes the same size/opcode shape the S2C path consumes.

---

## 7. Gaps

1. ~~Exact register contract~~ **Closed** — call site + full body image.
2. ~~Opcode dispatch seal (UF-012)~~ **Closed** — sole xref re-confirmed this residual.
3. ~~FailMission thiscall + return-ignored + EAX lifetime~~ **Closed**.
4. Full dual / product name of `FUN_005307e0` (framing sealed High; lifecycle dual open).
5. Semantics of `DAT_00d1ad10` object and `FUN_0092fd00`.
6. Whether S2C may omit character COID validation (handler never compares COID — trusts local char).
7. Runtime capture of abandon C2S → server → this handler.
8. Bit-exact / binary diff.

---

## 8. Verdict

**Identity as S2C FailMission packet handler is High / Confirmed.** Rename `Client_RecvFailMission` is justified. **UF-012 opcode wiring and full register/body framing are asm-sealed** (call site + 0x75-byte body through RET). Cleanup after FailMission is real (`FUN_005307e0` thiscall always runs) but the helper is not dual-reviewed as its own unit here.

**Verdict: accept-with-gaps** (secondary helpers / runtime only; framing residual **closed**).
