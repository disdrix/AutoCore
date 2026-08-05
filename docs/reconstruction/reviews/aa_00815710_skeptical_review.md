# Skeptical / adversarial review: `Client_PacketDispatch` @ `0x00815710`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | S2C sector/global packet switch + mission/inventory/skill/XP case claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Raw / annotated / clean / function record for `aa_00815710`; fresh Ghidra `batch_decompile` of `0x00815710` plus callees `0x00810f00`, `0x0080cac0`, `0x0080ff00`; `GameOpcode.cs`; inventory wire RE; mission topic notes; sibling grab/drop unit reviews.

**Not performed:** full disassembly (forbidden / avoided), live packet capture through every case, re-typing of formal parameters in Ghidra, xrefs for every FUN leaf.

---

## 2. Evidence used

Raw + fresh decompile prove:

1. Single large switch on first-class opcode dword from a packet-like object.
2. Outer range split at `0x8064` with special `0x8063` handling.
3. Explicit multi-case fallthrough cluster ending in shared no-op return-1.
4. Named Ghidra symbols on high-interest paths (CharacterLevel, inventory, credits, XP, mission dialog, objective complete/state).
5. Default unknown → return 0.

Comments and AutoCore enum names are **secondary** labels, not proven by this function body alone.

---

## 3. Attack results

### Claim 1 — This is the complete S2C game-packet router

| Sub-claim | Result |
|-----------|--------|
| Handles many `0x20xx` game opcodes | **Holds** (switch density). |
| Handles *all* sector S2C traffic | **Overstated.** Ghost create/update, TNL, login, and other queues exist outside this function (see tick order docs). |
| Every retail S2C opcode is either handled or returns 0 | **Unsealed** without full opcode inventory vs traffic. |

### Claim 2 — Priority opcode → handler bindings

| Opcode | Body evidence | Attack |
|--------|---------------|--------|
| `0x2017` → `Client_RecvCharacterLevel` | Direct call | **Holds** at symbol level |
| `0x205E` → `Client_RecvGiveCredits` | Direct call | **Holds**; **arg order / registers contested** (`unaff_*`) |
| `0x205F` → `Client_AwardKillExperience` | Direct call | **Holds**; body of award not this unit |
| `0x2031` → skill status | Direct call | **Holds** |
| `0x2035/39` grab responses | Shared call | **Holds** |
| `0x2037/3B` drop responses | Shared call | **Holds** |
| `0x203C` equip | Direct call | **Holds** |
| `0x2070` complete dynamic objective | Direct call | **Holds** (force-complete semantics live in callee) |
| `0x2071` objective state | Direct call | **Holds** |
| `0x206C` / `0x206D` mission paths | Direct calls | **Holds** at dispatch; do not collapse to one dialog |

### Claim 3 — `0x2030` skill cast appears in dispatch

| Sub-claim | Result |
|-----------|--------|
| Case `0x2030` present | **Falsified.** Absent from switch. |
| Clean fabricated a 0x2030 case | **Falsified.** Clean documents C2S-only absence. |
| Skill S2C is only 0x2031 | **Incomplete** — other skill-related S2C may exist under FUN leaves / different ranges. |

### Claim 4 — Inventory “equip/drop/grab” fully understood from this unit

Dispatch only proves **routing**. Grab/drop equip semantics, type maps, place callees, success bytes are **callee-owned**. Treating PacketDispatch comments as equip implementation evidence is **wrong**.

### Claim 5 — No-op fallthroughs are safe to ignore server-side

| Sub-claim | Result |
|-----------|--------|
| Client returns 1 without body work | **CF holds.** |
| Server may skip sending `0x2040`–`0x2043` SendAll | **Not sealed by this unit** — client ignoring ≠ server must not send; may still matter for other clients/versions. |
| `0x203D` EquipResponse no-op means equip is only 0x203C | **Probable** from this table; needs equip unit + traffic. |

### Claim 6 — Signature / types are reconstruction-grade

| Sub-claim | Result |
|-----------|--------|
| `__fastcall (void*, Packet_CharacterLevel*, void*)` | **Decompiler artifact.** Packet type is wrong for non-0x2017 cases. |
| `in_EAX` out-flag | **Consistent with Ghidra**; true C prototype unknown. |
| Clean “human refine” fixed ABI | **No** — comments only. |

### Claim 7 — GiveCredits / GiveXP argument plumbing

Clean and raw both pass `unaff_EDI` / `unaff_ESI` into credits and XP paths. That is a **red flag** for ABI recovery, not a sealed (client, packet) C signature. Callee `Client_RecvGiveCredits` plate says ESI=game, EDI=packet while dispatch call order is `(unaff_EDI, unaff_ESI)` — **internal tension** across units.

### Claim 8 — Clean is a finished reconstruction

It is a **comment-enriched scaffold** of a decompiler mega-switch. Not a portable C port of networking. Many leaves still `FUN_*`.

---

## 4. Alternate interpretations

### Minimal reading

Central S2C demux for game-opcode dwords: set a handled flag, switch, call a specialized recv or intentionally no-op, return whether known.

### Competing stories

1. **Some “no-ops”** might be handled earlier in the pipeline (filter before dispatch) so the switch never sees real traffic.
2. **Register-arg paths** might be decompiler failures that still work in binary due to calling convention — clean copying them is correct for scaffold fidelity but dangerous for reimplementation.
3. **`Packet_CharacterLevel *`** may be a forced type from Ghidra plate on one case applied to the whole function.

---

## 5. Confirmed despite skepticism

1. Switch structure, range gates, no-op cluster, high-opcode tail.
2. Named mission/XP/inventory/skill case targets present in decompile.
3. `0x2070` vs `0x2071` distinct handlers (historical swap risk acknowledged).
4. `0x2030` not an S2C case here.
5. Clean did not drop cases relative to raw / fresh decompile.
6. Fresh batch_decompile re-confirms raw body for this VA.

---

## 6. Critical contradictions / risks

### C1 — Formal packet type is a lie for most cases

Using `Packet_CharacterLevel` fields beyond a shared header risks wrong field names in ports.

### C2 — Credits/XP/grab register args

Cross-unit inconsistency can cause silent double-swap bugs in reconstructed C if someone “fixes” one unit without the other.

### C3 — Comment labels from GameOpcode.cs

Enum is AutoCore’s map, largely aligned with Ghidra plates, but **not** proven for every FUN leaf by this review. Misnamed intermediate opcodes remain possible.

### C4 — Scope inflation

Docs citing “PacketDispatch proves X gameplay rule” overreach unless X is pure routing.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | True ABI / out-flag | Yes for portable C |
| R2 | Full FUN leaf catalog | Yes for complete router port |
| R3 | Credits/XP register convention | Yes for money/XP paths |
| R4 | No-op opcode product intent | Partial |
| R5 | Live matrix of opcode → handler hits | Yes for seal |

---

## 8. Concrete checks performed

1. Diffed raw body vs 2026-07-23 `batch_decompile` for `0x00815710` (CF equal; whitespace/unicode only).
2. Enumerated switch case labels (121 including multi-case).
3. Verified absence of `0x2030`, `0x2034`, `0x2036`, `0x206E` cases.
4. Traced priority cases to named symbols matching clean.
5. Cross-checked GameOpcode names for comment risk (labels only).
6. Flagged GiveCredits call-site vs callee plate arg story.
7. Confirmed clean human refine added comments only (no CF invent).

---

## 9. Verdict

### **`needs-more-evidence`**

Dispatch shape and priority routes are real and scaffold-faithful. The unit is **not** sealed as a complete networking port: ABI, packet typing, register-arg paths, and unnamed leaves remain open. Safe use: **routing index** for mission/inventory/skill/XP S2C; unsafe use: sole authority for packet layouts or money/XP apply semantics.

### Stronger-verdict bar

1. Recover true prototype from callers (tick / queue drain).
2. Reconcile GiveCredits/GiveXP/grab register story with callees.
3. Name or link remaining FUN leaves for inventory/mission-adjacent opcodes.
4. Runtime hit counts for no-op vs active cases.
5. Shared packet header struct recovery.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Complete S2C router for all traffic | **Overstated** |
| 2 | Priority opcode bindings | **Hold at call sites** |
| 3 | 0x2030 in switch | **Absent (correct)** |
| 4 | Inventory semantics in this unit | **Routing only** |
| 5 | No-ops product-safe | **Unsealed** |
| 6 | Signature sealed | **Fail** |
| 7 | Credits/XP args sealed | **Contested** |
| 8 | Finished reconstruction | **Scaffold only** |

**Final verdict: `needs-more-evidence`**
