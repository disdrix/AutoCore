# Review B (skeptical / adversarial): `aa_006189d0` CVOGHBSkill_Common_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006189d0` |
| **VA** | `0x006189d0` |
| **Canonical name** | `CVOGHBSkill_Common_SpawnPerTargetHB_Inferred` (class **Confirmed**; method **Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md` |
| **System** | skills-abilities |
| **Live tools** | Independent decompile + `read_memory` + callers/xrefs + RTTI/vtbl chain |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/RTTI/vtbl+0x2c/spawn pipeline; reject ctor-identity / always-return-1 / free-helper / Runtime Confirmed / invent product English |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This VA **is** `CVOGHBSkill_Common_ctor` (partition parent list confusion) | **Falsified** — body is table loop + Enqueue/Start; **calls** ctor `0x00618180` |
| 2 | Free / non-virtual helper | **Falsified** — sole xref DATA @ Common vtbl+0x2c `0x009e1f58` |
| 3 | cdecl / no thiscall surface | **Falsified** — virtual slot; peer Execute ABI; `ret 0x18` |
| 4 | ECX this is required body state | **Partial** — ABI thiscall surface; body **ignores** ECX (like OnKill Execute) |
| 5 | Always returns 1 (Master/OnKill peer) | **Falsified** — epilogue `setne al` on spawnCount; can return 0 |
| 6 | Always starts every resolved HB | **Falsified** — owner-null → vtbl[0](1) without Enqueue; chance gate skips |
| 7 | Resolve is free function as decompiler shows | **Falsified** — bytes load `ECX=[world+0xe4e8]` |
| 8 | Child is base SkillBase only / size 0x6c0 | **Falsified** — `new(0x6d0)` + **Common_ctor** (not base+stamp) |
| 9 | Class inventable without RTTI | **Rejected invent** — `.?AVCVOGHBSkill_Common@@` via COL `0x00ab1820` |
| 10 | Product method name proven | **Open** — `_Inferred` required; no method string |
| 11 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |
| 12 | Same as SpawnEntities / OnKill / Master Execute | **Falsified** — different vtbl, child ctor, chance gate, events, return rule |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class Common | **Confirmed** | Wrong type hierarchy |
| vtbl+0x2c DATA install | **Confirmed** | Wrong virtual dispatch |
| ABI 6 stack + ret 0x18 + bool return | **High** | Stack smash / wrong success sense |
| Target table 0x10 / sentinel | **High** | Infinite loop / skip |
| Resolve thiscall world+0xe4e8 | **High** | Null resolve |
| HB 0x6d0 + Common_ctor(0, 1.0f) | **High** | Wrong action type/fields |
| Enqueue world+0xe4ec + Start | **High** | Skills never fire |
| Events 0x14/0x15 structural | **High** | Miss combat notify |
| Method product English | **None** | Overclaim design |
| Runtime / bit-exact | **Open** | Shipping image |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** drop Resolve `this` — `ECX = *(world+0xe4e8)`.  
2. Do **not** type chance second arg as pure `byte` — caller passes **ushort** from RNG slice.  
3. Do **not** assume return always `1` — **bool any-started**.  
4. Do **not** treat as subclass ctor — fanout **calls** Common ctor.  
5. Do **not** merge with Master/OnKill/SpawnEntities Execute — different child construction and side effects.  
6. Do **not** claim Runtime Confirmed without Launcher evidence.  
7. Parent name may appear as `FUN_00618180` or `CVOGHBSkill_Common_ctor` — same VA; do not edit parent dual.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| RTTI Common + vtbl+0x2c fanout CF | PDB method spelling |
| Child Common_ctor path size 0x6d0 | Gameplay design doc for “Common” |
| Chance gate + events 0x14/0x15 structural | Why designers chose event ids |
| Bool return on spawnCount | Exact product name of FUN_00589b80 |
| `_Inferred` method English | Terminal / Runtime Confirmed |

---

## 5. CF challenge of Review A

- Body bounds + ret 0x18: **agree Confirmed/High**  
- RTTI Common + slot: **agree Confirmed**  
- Bool any-started (vs always-1 peers): **agree High** — adversarial strengthens distinct return rule  
- Child Common_ctor(0, 1.0f): **agree High**  
- Product method English: **agree Open** → `_Inferred`  
- Runtime: **agree not claimed**

---

## 6. Surviving contract for AutoCore

```csharp
// CVOGHBSkill_Common_SpawnPerTargetHB_Inferred @ 0x006189d0
// retail: virtual vtbl+0x2c; 6 stack args; ret 0x18;
// return (spawnCount != 0); class RTTI Confirmed CVOGHBSkill_Common

bool SpawnPerTargetHB(CommonHb selfIgnored, Object source, SkillBlob skill,
                      WorldCtx world, TargetEntry* table, object tfid16, uint seed)
{
  // rngSlice = CloneSeededTable(seed)
  // for each table entry until (-1,-1,0):
  //   if chance_gate(skill+0xe4, rngSlice[i]): continue
  //   target = Resolve(*(world+0xe4e8), type, idLo, idHi)
  //   if target: new Common 0x6d0; Common_ctor(..., 0, 1.0f)
  //              owner? Enqueue(world+0xe4ec)+Start+events : dtor(1)
  // free rngSlice; return spawnCount != 0
}
```

**Verdict:** **accept-with-gaps** — Path B finds no CF rejects; invent-name and Runtime Confirmed claims rejected.
