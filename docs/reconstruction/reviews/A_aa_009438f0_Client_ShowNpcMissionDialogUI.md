# Review A (reconstruction fidelity): `aa_009438f0` Client_ShowNpcMissionDialogUI

| Field | Value |
|---|---|
| **Stable ID** | `aa_009438f0` |
| **VA** | `0x009438f0` |
| **Canonical name** | `Client_ShowNpcMissionDialogUI` |
| **Review date** | `2026-07-29` (dual residual strengthen: EAX all-4 + `+0x64c` byte store) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Present / reconfigure the NPC mission dialog UI for a chosen mission key:

1. Guard client dialog stack (`+0xf40`/`+0xf38`), local character (`+0xe98`), mission UI controller (`+0x1058`).
2. Resolve mission key from **EAX** (caller-framed) or multi-active journal shortcut when `mode≠0` and `EAX==-1`.
3. Lookup mission def; require awardable/objectives byte `(char)def[0x4c] != 0` (byte offset **0x130**).
4. Early-out `"NPC dialog already active!"` when same mission def + same NPC already open.
5. Probe turn-in readiness (`FUN_0052b420`); prepare C2S response opcode **0x206E**; set chrome mode and turn-in flag; finalize present.

Does **not** send network packets. Does **not** write HandleButton router state `+0x648`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `Client_ShowNpcMissionDialogUI` @ `0x009438f0` (≡ raw) |
| Raw | `docs/reconstruction/raw/aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Annotated | `docs/reconstruction/raw/aa_009438f0_Client_ShowNpcMissionDialogUI.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ShowNpcMissionDialogUI.cpp` |
| Function record | `docs/reconstruction/functions/aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Callers (asm via `get_assembly_context` + `read_memory`) | Recv `0x0081518c`; HandleButton state 3 `0x008ae93a`; list `0x008aecca`; unmapped `0x00924608` |
| Turn-in probe | Ghidra `FUN_0052b420` @ `0x0052b420` |
| Reward chrome | Ghidra `FUN_008aa760` @ `0x008aa760` — first store `dialog+0x64c`; reward labels |
| Reward region | Ghidra `FUN_0052dac0` @ `0x0052dac0` — returns state `+0x18` |
| Prepare | `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70` |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Scratch | `tmp/a_009438f0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Guards dialog stack + char `+0xe98` + UI `+0x1058` | **High** | Outer if chain |
| Multi-active + `EAX==-1` + mode≠0 → `Client_UpdateMissionJournal` | **High** | `char+0x510 > 1`; early return |
| Single/zero active + key −1 → first active id or empty return | **High** | `char+0x50c` list head |
| Mission def must have objectives byte `def[0x4c]` (off **0x130**) | **High** | Gate before show |
| `"NPC dialog already active!"` same def+NPC | **High** | String + `+0x670`/`+0x644` compare |
| `FUN_0052b420` = turn-in readiness probe | **High** | Last obj active + `FUN_0052a020` + optional NPC eval |
| Chrome mode `dialog+0x510` (`int*[0x144]`): 2=offer, 1=active/turn-in | **High** | Explicit stores; index→byte sealed vs `+0x644`/`+0x670` |
| Turn-in flag `dialog+0x64c` via `FUN_008aa760(..., uVar9)` | **High** | First store in helper; raw `MOV [EDI+0x64c],AL`; HandleButton state 1 + reward strings consume |
| Offer path double `FUN_008aa510` clear vs single on active/turn-in | **High** | Raw CF |
| Prepare stamps `+0x650=0x206E` on present path | **High** | Unconditional after already-active; chain |
| EAX mission key — **four** call sites | **High** | Asm sealed; site 4 same contract as Recv |
| Recv always passes `EAX=-1` mode=1 | **High** | `OR EAX,0xffffffff` at `0x00815189` |
| HandleButton re-show key from `dialog+0x518+idx*8` | **High** | Asm: `MOV EAX,[ESI+EDX*8+0x518]` |
| List-click key from `entry+0x500` | **High** | Asm in `FUN_008aec40` |
| Unmapped `0x00924608`: mode=1, `EAX=-1`, gated on `char+0x510≠EBX` | **High** (framing) / **Open** (product name) | Asm only; no Ghidra function |
| `FUN_0052dac0` → reward region `state+0x18` | **High** (CF) | Pass-through to `FUN_008aa760`; product name Tentative |
| Does not send packets | **High** | No send in body; Flush is separate |
| Does not write `+0x648` button router | **High** | No store in body |
| Chrome helper product names | **Tentative** | `FUN_008aaf60` / `008ac110` / `0092f090` / … |

---

## 4. Control flow: clean ≡ raw (spot-check)

| Stage | Raw present? | Clean match? |
|---|---|---|
| Outer guards (stack / char / UI) | Yes | **Yes** |
| mode==0 \|\| EAX≠−1 → def table | Yes | **Yes** |
| Multi-active journal + UpdateMissionJournal + finalize | Yes | **Yes** |
| Empty active list early return | Yes | **Yes** |
| First-active key from list node `[4]` | Yes | **Yes** |
| Def lookup + objectives byte gate | Yes | **Yes** |
| Already-active same mission+NPC early-out | Yes | **Yes** |
| Turn-in probe → Prepare → chrome helpers | Yes | **Yes** |
| Offer / active / turn-in branch + `FUN_008aa760` + finalize | Yes | **Yes** |
| Invented clamps / deleted branches | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra. No deleted branches.

---

## 5. Param / local renames (evidence only)

| Raw | Clean / plate | Evidence |
|---|---|---|
| `param_1` | client / UI root | offsets `+0xe98` char, `+0x1058` dialog, `+0xf40` stack; callers pass `&DAT_00d1a840` |
| `param_2` | NPC object | compared to `dialog+0x644`; from Recv resolve / HandleButton `+0x644` |
| `param_3` | mode | Recv **1**, re-show/list **0**, unmapped site **1**; gates journal shortcut |
| `in_EAX` | mission key | Asm at all four call sites |
| `piVar2` | mission dialog UI* | `*(client+0x1058)`; layout matches HandleButton dialog |
| `puVar6` | mission def* | `CNDHash_LookupByKey` result |
| `uVar7` | reward region* | `FUN_0052dac0(*def,0)` → `state+0x18` |
| `uVar9` | turn-in flag | → `FUN_008aa760` → `dialog+0x64c` |

Remaining helpers stay `FUN_*` until product names are evidence-backed.

---

## 6. Gaps / open questions

1. Who writes HandleButton router **`+0x648`** relative to Show’s **`+0x510`** chrome mode.
2. Product names for chrome / finalize helpers.
3. Product name for unmapped caller block at **`0x00924608`** (EAX framing sealed).
4. Runtime open / bit-diff vs retail EXE.

**Verdict:** NPC dialog present hub CF faithful; EAX framing (4/4 xrefs) and `+0x64c` turn-in handoff sealed. **accept-with-gaps.**
