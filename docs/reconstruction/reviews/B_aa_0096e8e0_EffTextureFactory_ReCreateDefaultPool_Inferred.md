# Review B (skeptical / adversarial): `aa_0096e8e0` EffTextureFactory_ReCreateDefaultPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e8e0` |
| **VA** | `0x0096e8e0` |
| **Canonical name** | `EffTextureFactory_ReCreateDefaultPool_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md` |
| **System** | palantir graphics Effects — effTextureFactory |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Thiscall ECX=factory | SEH prolog loads `mov eax,[esp+10h]`; parent **pushes** factory | **Falsified** thiscall |
| 2 | Plain RET / no stack cleanup | Epilogue **`C2 04 00`** | **Falsified** |
| 3 | Recreates *all* textures | Gate `impl+0x30 == 0` skips non-DEFAULT | **Falsified** all-claim |
| 4 | Is the Reset pre-release walk | Pre-release is separate loop calling `FUN_0096c8e0`; this runs **after** device Reset | **Falsified** merge |
| 5 | Returns void | `mov eax,edi` + parent `test eax,eax` / fail plate | **Falsified** |
| 6 | Scaffold name alone is product-complete | String is ReCreate of **effTextureImpl** from **factory.cpp** — need role plate | **Agree** reject bare scaffold as sole name |
| 7 | `+0x30` is "state enum" free invent | Create stores pool pointer param into `+0x30`; 0 ⇒ DEFAULT pool (lost on Reset) | **High** DEFAULT-pool reading |
| 8 | Multiple callers | xrefs = 1 (`GfxDevice_Reset` only) | **Falsified** multi-caller |
| 9 | Fail continues list | Early `return iVar5` on hr<0 | **Falsified** continue-claim |
| 10 | Same VA as env-sector ReCreate strings | Env uses `FUN_0048edc0` with different fail strings | **Falsified** merge |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 4 / stack factory / hr | **Confirmed** | Stack imbalance / Reset fail |
| List walk + DEFAULT gate | **Confirmed** | Missed / double recreate |
| Create callee + fail log | **Confirmed** | Silent fail / wrong plate |
| `0x3000` / `+0x4c` role | **Open** | Wrong branch port |
| `FUN_0096cad0` formal order | **Probable** | Call-site bytes guide; Ghidra signature noisy |
| Runtime | **Open** | No live Reset |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04)
body 260 B ends C2 04 00; pad CC then FUN_0096e9f0

Prolog: FS:[0] SEH LAB_009b09a1; mov eax,[esp+0x10] (factory)
List: mov eax,[eax+8]; mov ebp,[eax] (first node); compare to head
Gate: mov ebx,[esi+0x30]; test ebx,ebx; jnz skip
Flags: test [esi+0x2c], 0x3000
Create path: push formals; mov ecx,esi; call FUN_0096cad0
Fail: FUN_0096a630 → c_str → FUN_0076cec0 → vog_LogMessage(...0x159...) → dtor → ret hr
Success: ret 4 with eax=hr
```

### Parent trap

Reset decompile may elide the push — **bytes** at `0x0075f2bb`: `mov edx,[ebp+0x754]; push edx; call FUN_0096e8e0`. Factory lives at gfxDevice `+0x754` (`param_1[0x1d5]`).

### Create trap

Do not re-implement recreate logic inside this VA — always delegate to `FUN_0096cad0` (which itself calls `FUN_0096c8e0` first). Porting create body here would double-release incorrectly if not careful.

### Naming trap

`Named_effTextureFactory_0096e8e0` is a string-derived plate without ReCreate/DefaultPool role — keep structural `_Inferred` name.

---

## 4. Residual risks

| Risk | Severity | Mitigation |
|---|---|---|
| Mis-ordered create formals | Med | Seal create dual from its call-site bytes |
| `0x3000` branch wrong COM this | Low/Med | Match decompile `(*(*+0x4c))+8` |
| List node layout wrong | Low | Head+next+value@+8 used consistently with Reset walk |

---

## 5. Verdict

Attacks on thiscall, void-return, all-textures, and pre-release-merge fail. Core sealed; nested create dual + flag English open → **accept-with-gaps**.
