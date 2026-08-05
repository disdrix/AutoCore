# Review A (reconstruction fidelity): `aa_005d4440` CVOGObject_SwitchHBAIByCode

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4440` |
| **VA** | `0x005d4440` |
| **Canonical name** | `CVOGObject_SwitchHBAIByCode` (inferred) |
| **Ghidra symbol** | `FUN_005d4440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005d4440_CVOGObject_SwitchHBAIByCode.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Switch the object's current **HBAI** instance (`this+0x3c`) to a new **AICode** (`param_2`). Early-outs if the current AI's code (via AI vtbl **+0x18**) already equals `param_2`.

Handles transitions among:

* **Normal codes** (1..5 via `CVOGHBAI_CreateByAICode`)
* **Code 6** — `CVOGHBAIWalkingCreatureTurreted` (alloc size stamp `0xD0`)
* **Code 7** — `CVOGHBAIBase_Default` (alloc size stamp `0xD0`)

Special casing treats 6/7 as a separate “base/turret” family (`bVar1`/`bVar2` false when code∈{6,7}). Transitions between families use `FUN_0055dfb0` (default AI resolver) and AI link vtbl **+0x78 / +0x7c**. Finishes by pointing `this+0x14` at `AI+0x60`, setting `this+0x40 = (code==7)`, and balancing lock helpers `FUN_005d4370(0x10)` / `FUN_005d43e0`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005d4440_FUN_005d4440.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_005d4440_FUN_005d4440.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005d4440.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005d4440.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_005d4440_FUN_005d4440.md` | Scaffold |
| Live decompile | Ghidra MCP `0x005d4440` | **≡ raw** |
| Factory dual | `reviews/A_aa_005d3d10_CVOGHBAI_CreateByAICode.md` | AICode 1..6+default |
| Callers | Ghidra xrefs (7 funcs) | Create/spawn / network / AI |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=object; stack AICode int | **High** | Decompile + callers pass 6 etc. |
| Current code = `(*(*(this+0x3c))->vtbl)[+0x18]()` | **High** | First call |
| Early return if current == requested | **High** | |
| Codes 6 and 7 are special family (not CreateByAICode path for enter-6/7) | **High** | Explicit ctors |
| Code 7 → `CVOGHBAIBase_Default_ctor` | **High** | Named Ghidra symbol |
| Code 6 → `CVOGHBAIWalkingCreatureTurreted_ctor` | **High** | Named Ghidra symbol |
| Alloc via `DAT_00b05060` vtbl+0x10; stamp `*(u16*)(alloc+4)=0xD0` | **High** | Matches factory dual sizes |
| Normal family: `CVOGHBAI_CreateByAICode(code, radius/profile float)` | **High** | Two call sites |
| Profile float from `FUN_00404d40` after AI vtbl+0x24 pack | **High** (CF) / **Probable** (semantic) | |
| Copy AI fields `+0x14/+0x18` onto new instance | **High** | |
| Old AI destroy via `(*old->vtbl)(1)` on several paths | **High** | |
| Link hooks vtbl **+0x78** / **+0x7c** | **High** (slots) / **Tentative** (English) | Parent/child AI link |
| Gate: enter normal-from-special requires `FUN_0055dfb0()!=0` | **High** | Early return if 0 |
| Epilogue: `this+0x14 = AI+0x60`; `this+0x40 = (code==7)` | **High** | |
| Lock pair `FUN_005d4370(0x10)` / `FUN_005d43e0` | **High** (call order) / **Tentative** (name) | |
| Optional pose save/restore when `this+8≠0` and code 7 transitions | **High** (CF) | `5617c0/561580` pre; `560f70/560f30` post |
| AICode English table | **Probable** | From CreateByAICode dual (1..5) + 6/7 special |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Read curCode via AI vtbl+0x18 | Yes |
| Same-code early return | Yes |
| Classify requested/cur as special (6/7) | Yes |
| Block special→normal if default AI resolver null | Yes |
| Lock enter; optional code-7 pose stash | Yes |
| Branch: normal←special / normal←normal / special←* | Yes |
| CreateByAICode or explicit Default/WalkingTurreted ctors | Yes |
| Link/destroy old AI; install new at `this+0x3c` | Yes |
| Fixup `+0x14`, `+0x40`; unlock; optional pose restore | Yes |

### AICode family map (Probable / High)

| Code | Path in this unit | Factory dual |
|---:|---|---|
| 1..5 | `CVOGHBAI_CreateByAICode` | Character/Creature/Bot/Mine/Driver |
| 6 | `CVOGHBAIWalkingCreatureTurreted_ctor` | WalkingTurreted (0xD0) |
| 7 | `CVOGHBAIBase_Default_ctor` | Base_Default (0xD0) / factory default |

### Authoritative skeleton

```
SwitchHBAIByCode(obj, newCode):
  old = obj.ai (+0x3c)
  cur = old->getAICode()          // vtbl+0x18
  if cur == newCode: return

  reqNormal = newCode not in {6,7}
  curNormal = cur not in {6,7}
  if reqNormal and not curNormal and !DefaultAI(): return

  lockedFlag = obj+8
  Lock(0x10)
  if lockedFlag:
    if cur==7: SavePose(...)
    if newCode==7: PreSwitch(...)

  // family-dependent replace of obj.ai (CreateByAICode / explicit ctors /
  // DefaultAI intermediate / vtbl+0x78/+0x7c link / scalar delete)

  obj.field_14 = obj.ai + 0x60
  obj.byte_40 = (newCode == 7)
  if lockedFlag:
    if cur==7: RestorePose(...)   // NOTE: uses iStack_5c which may be clobbered — see gaps
    if newCode==7: PostSwitch(...)
  Unlock()
```

---

## 5. Callers (live xrefs)

| Function | Role (Probable) |
|---|---|
| `FUN_004ed470`, `FUN_004f2930` | Create / spawn paths (pass code 6) |
| `FUN_004c4560` | Creature setup |
| `FUN_0053d430`, `FUN_0053d970`, `FUN_0053dbb0` | Network / state apply |
| `FUN_005d4700` | AI maintenance sibling |

---

## 6. Gaps / open

1. Exact product name of object type (`CVOGCreature` vs broader `CVOGObject`).
2. English for AI vtbl +0x18/+0x24/+0x78/+0x7c.
3. `FUN_0055dfb0` dual (default AI singleton / factory).
4. Whether epilogue `if (iStack_5c == 7)` still sees **original** curCode after paths that overwrite `iStack_5c` (decomp risk — **Medium** residual).
5. Full pose save/restore helpers `5617c0/561580/560f70/560f30`.
6. Runtime capture of AICode transitions.

**Verdict:** **accept-with-gaps** — **switch CF + code 6/7 special ctors + CreateByAICode path + epilogue flags** sealed; product names, link vfuncs, and one decomp clobber residual open.
