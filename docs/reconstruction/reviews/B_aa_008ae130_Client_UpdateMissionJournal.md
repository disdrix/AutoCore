# Review B (skeptical / adversarial): `Client_UpdateMissionJournal` @ `0x008ae130`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008ae130_Client_UpdateMissionJournal.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (residual dual; supersedes 2026-07-23 open id-vector / FailMissionNotify risks) |
| **Verdict** | **accept-with-gaps** on CF + partition; **reject** claims that this unit fails missions or that `FUN_00568200` fills id vectors |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always rebuilds journal | **Falsified** — only when state==3 **and** client singleton set |
| 2 | FailMissionNotify fails the mission | **Falsified at this site** — body is Vector_PushDword only; no dirty bit / FailMission / packets |
| 3 | `FUN_00568200` collects / partitions ids | **Falsified** — live body is tree **iterator++**; partition is the `LEA ECX` branch into Active vs New vectors before push |
| 4 | “New Missions” provenance unknown | **Sealed** — same `+0x50c` walk; New when hash miss **or** hash node `[+0x8]==0` |
| 5 | Active list walk alone implies all ids Active | **Falsified** — Active only if hash hit **and** `[node+0x8]!=0` |
| 6 | Bit-for-bit UI layout portable | **Overstated** — SEH + float spacing + unnamed vcalls |
| 7 | Required for accept/claim protocol | **Overstated** — cosmetic/manager UI; accept/claim is HandleButton |
| 8 | Widget base `0x9c4f` is a mission table index | **Unproven** — sequential control ids only; no table load from `0x9c4f` |
| 9 | Ready for complete / bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow (assembly-backed)

```
if (dialog[0x192] != 3 || DAT_00d1b6d8 == 0) return

init chrome; optional NPC name header
y = layout from dialog[0x1b8] (optional)

activeVec = empty; newVec = empty   // stack triads under ESP+0x24 / ESP+0x34 objects
it = *header(char+0x50c)
if it == header: skip panels (still free empty vectors)

while it != header:
  id = *(it + 0x10)
  node = hash_lookup(char+0x540, id)
  if node != null && *(node + 0x8) != 0:
    Vector_PushDword(activeVec, id)     // CALL 0x004149d0, ECX=ESP+0x24
  else:
    Vector_PushDword(newVec, id)        // ECX=ESP+0x34
  it = tree_iterator_next(it)           // CALL 0x00568200, ECX=&it

if activeCount > 0:
  build "Active Missions:" panel
  for i in 0..activeCount-1:
    lookup def by activeIds[i]; FUN_00547920(0)
    entry widget 0x510; set control id i+0x9c4f; layout

if newCount > 0:
  build "New Missions:" panel
  for i in 0..newCount-1:
    lookup def by newIds[i]; FUN_00547920(0)
    entry widget; control id activeCount+0x9c4f+i
    push entry* into dialog child vector [0x1ca..]

free newVec; free activeVec
```

Live decompile of `0x008ae130` matches 2026-07-23 raw **for outer CF**. Residual seal is assembly interpretation of the push branch + callee bodies (decompiler collapses both LEAs into a single `FailMissionNotify` + bare `FUN_00568200()`).

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State-3 gate | **High** | Journal thrash in wrong mode |
| Tree walk `+0x50c` + iterator++ | **High** | Infinite loop / skip all |
| Hash `+0x540` + partition predicate | **High** | Wrong Active vs New panel |
| Vector_PushDword (named FailMissionNotify) | **High** | Accidental fail side effects if misread |
| No fail/grant/network in unit | **High** | Protocol overclaim |
| Panel strings | **High** | Localization only |
| Entry ctor XML mselect | **High** | Wrong widget class |
| `+0x8` product field English | **Probable** | Misname only; branch sealed |
| UI vtable product names | **Low** | Cosmetic ports |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `FUN_00568200` fills vectors | Hidden push? | **No** — is_nil iterator walk only |
| FailMissionNotify mutates mission | Side channel? | **No** — store dword + advance end |
| New ids from separate list | Second loop? | **No** — single walk; dual LEA destinations |
| `0x9c4f` mission id | Table base? | **No evidence** — additive control id |
| Active empty skips New | Shared skip? | **No** — New checked independently at `ESP+0x38` |
| Child vector only for New entries | Active also? | **Yes holds** — push at `[0x1ca..]` only on New path |

---

## 5. Surviving contract for AutoCore

```
When dialog state==3 and client singleton live:
  walk char+0x50c mission tree
  for each id @ node+0x10:
    if hash(char+0x540) hits and node+0x8 non-null → Active ids
    else → New ids
  rebuild Active / New panels (UI only)
  do not grant / complete / fail missions

ShowNpc multi-active path may open this journal view.
FailMissionNotify name is historical; treat as Vector_PushDword at this site.
FUN_00568200 is tree iterator++, not id collection.
```

---

## 6. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Runtime journal with mixed Active+New ids | **Yes** for complete / bit-exact |
| R2 | Hash node `+0x8` product name | No for CF (predicate sealed) |
| R3 | UI vtable slot names | No for progression authority |
| R4 | `char+0x50c` English (“active list” vs “journal set”) | Mild naming only |

---

## 7. Concrete checks performed

1. Live re-decompile `0x008ae130` — matches raw outer CF.
2. Live decompile `FUN_00568200` — iterator++ with `+0x49` is_nil.
3. Live decompile `CVOGReaction_FailMissionNotify` — capacity push / grow.
4. Assembly at `0x008ae31e`–`0x008ae350` — dual LEA destinations + push + iterator.
5. Post-loop empty checks `ESP+0x28` / `ESP+0x38` and `(end-begin)>>2` counts.
6. Entry ctor `FUN_00829ec0` XML string.
7. Sole caller xref `ShowNpcMissionDialogUI`.
8. Attacked 2026-07-23 dual residual claims — **resolved static**.

---

## 8. Verdict

### **accept-with-gaps**

Id-vector residual is **closed static**. Prior skeptical risks (FailMissionNotify mutation; unknown New provenance; FUN_00568200 as collector) are **falsified**. Package remains **not complete** without runtime/diff.

### Stronger-verdict bar (complete)

1. Runtime: multi-active + offered-new journal capture → panel membership matches partition predicate.
2. Optional: name hash `+0x8` from instance ctor / layout unit.
3. Bit-exact UI layout deferred unless product requires pixel parity.

---

## 9. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | State-3 journal rebuild | **Holds** |
| 2 | FailMissionNotify fails mission here | **Falsified** |
| 3 | FUN_00568200 collects ids | **Falsified** (iterator++) |
| 4 | Active/New partition sealed | **Holds** |
| 5 | UI-only / no progression authority | **Holds** |
| 6 | Finished complete / bit-exact | **Fail** |
