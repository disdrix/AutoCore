# Annotated low-level: MedalUI_RefreshPagedAchievementSlots_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0090cbc0` |
| VA | `0x0090cbc0`–`0x0090cdfe` (**575 B** / `0x23F`) |
| Ghidra | `FUN_0090cbc0` |
| Canonical | `MedalUI_RefreshPagedAchievementSlots_Inferred` |
| System | `missions-progression` |
| Date | 2026-08-05 (MEGA-063 dual seal) |
| Evidence | Live decompile + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` |

---

## Machine-level notes

- **ABI:** **EAX** = MedalUI host on entry (`MOV ESI,EAX`). No stack formals. Void. Bare **`RET`** (`C3`).
- **Manager:** `DAT_00d1b6d8` (medal/achievement manager singleton) required non-null.
- **Gate:** host `vtbl[+0x3d8]()` must return non-zero (visible/active).
- **Host layout (dwords):**
  - `+0x50c` — page index (scroll row steps)
  - `+0x5a0` — scrollbar / pager widget*
  - `+0x5a4` — max page index
  - `+0x540` — button slot array base used by prep/apply siblings (24 slots)
- **Constants:** slot cap **0x18** (24); row stride **3**; page formula `(count - 25) / 3 + 1` when count > 24.
- Prefer assembly when decompiler conflicts (decompiler `in_EAX` is real; `count < 0x19` ≡ `count <= 0x18`).

---

## Control flow (annotated)

```text
host = EAX
manager = DAT_00d1b6d8
if manager == 0: return
if host->vtbl[+0x3d8]() == 0: return

MedalUI_PrepClearButtonSlots_Inferred()   // EDI=host  (FUN_0090c700)
filled = 0
count = MedalUI_CountDisplayableEntries() // EBX=manager (FUN_0090c810)

if count <= 0:
  host.pageIndex (+0x50c) = 0
  if host.scrollbar (+0x5a0): scrollbar->vtbl[+4](0)
  return

// page math
maxPage = (count - 25) / 3 + 1          // signed div magic 0x55555556
if count <= 24:
  maxPage = 0
  pageIndex = 0
else if pageIndex > maxPage:
  pageIndex = maxPage
host.maxPage (+0x5a4) = maxPage

// scrollbar widget
sb = host.scrollbar (+0x5a0)
if sb != 0:
  if maxPage == 0:
    sb->vtbl[+0xcc](0)                  // hide
  else:
    sb->vtbl[+0xcc](1)                  // show
    sb->vtbl[+0x460](1.0f / maxPage)    // g_flOne / maxPage
  sb->vtbl[+0x34c]()                    // refresh

walkIndex = -1
// Loop A — owned/vector medals [manager+0x574, +0x578)
for it in vector:
  if filled >= 24: break
  medal = FUN_0051a0e0(*it)
  if medal == 0: continue
  walkIndex++
  if walkIndex < pageIndex * 3: continue
  FUN_0090c9a0(medal, flag=1)           // apply achievement button; EBX=slot
  filled++

// Loop B — hash table medals at manager+0x540
hash = *(manager+0x540)
if hash.lock (+0x1d) already set: log HashError:TraversalLock + VOG_DEBUG_STOP
hash.lock = 1
node = 0
while filled < 24:
  if hash.lock clear: log HashError:TraverseToNext + VOG_DEBUG_STOP
  node = (node==0) ? hash.head(+0x14) : node->next(+0x14)
  payload = node ? node->payload(+8) : 0
  if payload == 0: break
  medal = FUN_0051a0e0(*(payload+0x100))
  if medal == 0: continue
  walkIndex++
  if walkIndex < pageIndex * 3: continue
  FUN_0090c9a0(medal, flag=0)
  filled++
hash.lock = 0
return
```

---

## Pseudocode (annotated copy of raw + ABI)

```c
// Retail ABI: EAX = MedalUI host*; void; bare RET
void MedalUI_RefreshPagedAchievementSlots_Inferred(void /* EAX = host */)
{
  int *host = /* EAX */;
  int manager = DAT_00d1b6d8;
  char visible;
  int count, filled, maxPage, walkIndex;
  int *it;
  int medal, node, payload;

  if (manager == 0) return;
  visible = (**(code **)(*host + 0x3d8))();  // ECX=host
  if (visible == 0) return;

  // EDI = host
  FUN_0090c700();                         // MedalUI_PrepClearButtonSlots_Inferred
  filled = 0;
  // EBX = manager
  count = FUN_0090c810();                 // MedalUI_CountDisplayableEntries_Inferred

  if (count <= 0) {
    host[0x143] = 0;                      // +0x50c pageIndex
    if ((int *)host[0x168] != 0) {        // +0x5a0 scrollbar
      (**(code **)(*(int *)host[0x168] + 4))(0);
    }
    return;
  }

  maxPage = (count - 0x19) / 3 + 1;
  host[0x169] = maxPage;                  // +0x5a4
  if (count <= 0x18) {
    host[0x169] = 0;
    host[0x143] = 0;
  } else if (maxPage < host[0x143]) {
    host[0x143] = maxPage;
  }

  if ((int *)host[0x168] != 0) {
    if (host[0x169] == 0) {
      (**(code **)(*(int *)host[0x168] + 0xcc))(0);
    } else {
      (**(code **)(*(int *)host[0x168] + 0xcc))(1);
      (**(code **)(*(int *)host[0x168] + 0x460))(g_flOne / (float)host[0x169]);
    }
    (**(code **)(*(int *)host[0x168] + 0x34c))();
  }

  it = *(int **)(manager + 0x574);
  walkIndex = -1;
  do {
    if (it == *(int **)(manager + 0x578)) break;
    medal = FUN_0051a0e0(*it);
    if (medal != 0) {
      walkIndex++;
      if (walkIndex >= host[0x143] * 3) {
        FUN_0090c9a0(medal, 1);           // MedalUi_ApplyAchievementSlotButton
        filled++;
      }
    }
    it++;
  } while (filled < 0x18);

  // hash traverse manager+0x540 with lock +0x1d ...
  // FUN_0090c9a0(medal, 0) for remaining slots
  // unlock; return
}
```

---

## Callers (why this unit exists)

| Site | Parent | Role |
|---|---|---|
| `0081015f` | `Client_RecvCompleteDynamicObjective` (S2C **0x2070**) | Post–force-complete medal UI refresh |
| `0080ce87` | `FUN_0080ce50` | JMP tail after local medal-related gate |
| `0090d364` | `FUN_0090d0d0` | Achievements window init (`i_d_a_2d_wnd_bg_achievements.xml`) |
| `009473a5` | `FUN_00946c00` | UI path (host from ESI) |
| `0090ce73` / `00952bb1` | additional UI refresh sites | EAX=host seeds |

---

## Sibling chain (not dualled here except as callees)

```text
FUN_0090cbc0  MedalUI_RefreshPagedAchievementSlots_Inferred  [OWN MEGA-063]
  ├─ FUN_0090c700  MedalUI_PrepClearButtonSlots_Inferred     [dualed MEGA-102]
  ├─ FUN_0090c810  MedalUI_CountDisplayableEntries_Inferred  [sibling]
  ├─ FUN_0051a0e0  medal-def resolve by id                   [shared]
  ├─ FUN_0090c9a0  MedalUi_ApplyAchievementSlotButton_Inferred [sibling dual]
  └─ FUN_007a4480  debug log (HashError / VOG_DEBUG_STOP)
```

---

## Open questions

- Product demangle for host / manager / scrollbar classes.
- Exact semantics of apply `flag` 0 vs 1 (vector vs hash source).
- Runtime / bit-exact / differential verification.
