# Review B (skeptical / adversarial): `Client_ShowNpcMissionDialogUI` @ `0x009438f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009438f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen: EAX all-4 + `+0x64c` byte/`MOV` seal) |
| **Counterpart** | `reviews/A_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| **Verdict** | **accept-with-gaps** on present/reconfigure hub CF; **needs-more-evidence** on chrome helper names + `+0x648` writer + product name of `0x00924608` block |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `param_3` alone selects journal | **Overstated** — journal only when mode≠0 **and** EAX==−1 **and** active count>1 | **Falsified as sole selector** |
| 2 | Dialog state `[0x144]` == HandleButton `+0x648` | **Falsified** — `[0x144]` is byte **`+0x510`**; `+0x648` never written here | **Survives as distinct fields** |
| 3 | Always opens dialog for any mission | **Falsified** — requires objectives byte `def[0x4c]` | **Survives** |
| 4 | Already-active string aborts all paths | **Partial** — only when UI-open probe `vtbl+0x3d8` succeeds **and** same mission+NPC | **Survives with conditions** |
| 5 | EAX mission key framing is unrecoverable | **Falsified** — four call sites seal EAX | **Closed** |
| 6 | Recv path passes a specific mission id in EAX | **Falsified** — Recv does `OR EAX,-1` then CALL | **Survives: always −1** |
| 7 | Show sends MissionDialogResponse | **Falsified** — Prepare only; Flush sends | **Survives** |
| 8 | `FUN_0052b420` is decorative | **Falsified** — drives chrome mode 1 + `uVar9=1` → `+0x64c` | **Survives as turn-in probe** |
| 9 | Clean deleted branches vs raw | **Falsified** — spot-check all stages present | **Survives** |
| 10 | mode=0 never uses EAX | **Falsified** — mode=0 still looks up def by EAX; re-show/list set EAX to real keys | **Survives** |
| 11 | Orphan `0x00924608` has unknown EAX | **Falsified this pass** — same as Recv: mode=1, `OR EAX,-1`, gated on `char+0x510≠EBX` | **Framing closed; product name open** |
| 12 | `+0x64c` is only a HandleButton flag | **Partial** — also selects reward chrome strings inside `FUN_008aa760` | **Survives as claim-mode bit** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-active journal branch | **High** | Wrong multi-mission UX |
| Recv / unmapped `EAX=-1` + mode=1 contract | **High** | Wrong mission shown after open |
| HandleButton / list real-key EAX | **High** | Wrong re-show / list pick |
| Offer `+0x510=2` vs active/turn-in `=1` | **High** | Accept/claim chrome wrong |
| Turn-in `+0x64c` via `FUN_008aa760` first store | **High** | HandleButton accept vs claim inverted |
| `+0x64c` also drives reward caption strings | **High** | Cosmetic only if wrong; semantics still claim-mode |
| `FUN_0052b420` readiness spine | **High** | Claim path not offered when ready |
| Prepare 0x206E on show | **High** | Cancel/close flush incomplete body |
| `FUN_0052dac0` → `state+0x18` reward region | **High** (CF) | Empty/wrong reward icons |
| `+0x648` relationship to `+0x510` | **Tentative** | UI automation state matrix wrong |
| Chrome FUN_* product names | **Tentative** | Mis-named helpers in port notes |
| Product function owning `0x00924608` | **Open** | Unknown alternate entry name |

---

## 3. Cross-check against raw / asm

### 3.1 Present spine (authoritative)

```
if dialogStack && char && missionUI:
  if mode==0 || EAX != -1:
    defTable = FUN_0053fff0()
  else:  // mode≠0 && EAX==-1
    if activeCount > 1:
      open/ensure UI; UpdateMissionJournal; finalize; return
    if empty active list: return
    defTable = FUN_0053fff0(); EAX = firstActive.missionId
  def = Lookup(defTable, EAX)
  if def && def.objectivesByte:
    ensure UI; maybe already-active log+return
    turnIn = FUN_0052b420(def, npc)
    PrepareResponseOpcode()          // +0x650 = 0x206E
    header/rewards = FUN_0052dac0(...) // state+0x18
    if !turnIn:
      if !active(def):  chrome +0x510=2; double clear slots; flag=0
      else:             chrome +0x510=1; single clear; flag=0
    else:
      chrome +0x510=1; single clear; flag=1
    FUN_008aa760(rewards, 4, flag)   // *(dialog+0x64c) = flag (byte)
    finalize
```

### 3.2 EAX call-site seals (asm / `get_assembly_context` + `read_memory`)

| Site | Mode push | EAX | Notes |
|---|---|---|---|
| Recv `0x00815189`–`8c` | 1 | **−1** (`OR EAX,0xffffffff`) | After staging 0x206D offers |
| HandleButton `0x008ae925`–`3a` | 0 | `*(dialog+0x518+idx*8)` | NPC from `+0x644` first into EAX then pushed; key reloaded after |
| List `0x008aecae`–`ca` | 0 | `*(entry+0x500)` | NPC from `dialog+0x644` in EDX |
| Unmapped `0x009245f1`–`08` | 1 | **−1** | Only if `*(char+0x510) != EBX`; no Ghidra function |

### 3.3 `+0x64c` write seal (`FUN_008aa760`)

```
// entry of FUN_008aa760 (decompile + raw bytes)
FUN_007a69d0();
*(byte*)(dialog + 0x64c) = param_3;   // MOV [EDI+0x64c], AL  (88 87 4c 06 00 00)
*(dialog + 0x578/57c) = -1;
*(dialog + 0x514) = 0;                // reward icon count
// then up to param_2 (Show passes 4) reward slots from param_1
// caption branch on *(char*)(dialog+0x64c):
//   0 → "You Will Receive:" / "You Will Get To Choose From:"
//   1 → "Your Reward:" / "Select A Reward:"
```

HandleButton state 1: `+0x64c==0` → GiveMission; `≠0` → CompleteObjective.

### 3.4 Field distinctness

| Field | Writer in this unit? | Consumer |
|---|---|---|
| `+0x510` | **Yes** (Show) | Chrome / helpers |
| `+0x64c` | **Indirect** (`FUN_008aa760`) | HandleButton state 1 + reward captions |
| `+0x648` | **No** | HandleButton router |
| `+0x650` | **Indirect** (Prepare) | Flush send |
| `+0x644` / `+0x670` | Compared (not set here for already-active) | Already-active + later fill |

Clean preserves spine. **No deleted branches.**

---

## 4. Surviving contract for AutoCore

```
ShowNpcMissionDialogUI(client, npc, mode)  // missionKey in EAX
  require dialog stack + local character + mission UI
  if mode!=0 and missionKey==-1 and activeCount>1:
    UpdateMissionJournal; return
  if mode!=0 and missionKey==-1 and activeCount<=1:
    missionKey = first active id (or return if empty)
  resolve mission def; require objectives byte
  if same mission+NPC already open and UI open: log; return
  turnIn = TurnInReady(def, npc)           // FUN_0052b420
  PrepareResponseOpcode()                  // +0x650 = 0x206E; no send
  set chrome +0x510 = (offer? 2 : 1)
  set +0x64c = turnIn via reward chrome helper (byte)
  finalize present
Does not send network packets.
Does not set button-router +0x648.
RecvNpc and unmapped 0x00924608 always call with mode=1, EAX=-1
  (unmapped also requires char+0x510 != EBX).
HandleButton state3 / list click: mode=0, EAX = real mission key.
```

---

## 5. Open questions

1. Exact writer of **`+0x648`** (0/1/2/3) after Show sets **`+0x510`**.
2. Whether cancel/close can flush prepared 0x206E with incomplete payload (chain open).
3. Product names for chrome helpers and full reward layout beyond `state+0x18`.
4. Product function for unmapped block **`0x00924608`** (framing sealed).
5. Live capture of multi-active journal vs single offer/turn-in.

**Verdict:** Safe as present/reconfigure hub; EAX (4/4) and `+0x64c` handoff sealed with raw store + dual consumers. Leave `+0x648` writer, chrome FUN_* names, and `0x00924608` product name open. **accept-with-gaps.**
