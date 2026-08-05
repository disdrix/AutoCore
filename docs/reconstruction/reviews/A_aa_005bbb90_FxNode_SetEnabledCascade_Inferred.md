# Review A (reconstruction fidelity): `aa_005bbb90` FxNode_SetEnabledCascade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbb90` |
| **VA** | `0x005bbb90` |
| **Body span** | `005bbb90` – ~`005bbc1d` (+ epilogue paths; `ret 8`) |
| **Canonical name** | `FxNode_SetEnabledCascade_Inferred` |
| **Ghidra name** | `FUN_005bbb90` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_005bbb90_FxNode_SetEnabledCascade_Inferred.md` |
| **System** | client special-FX host active-flag cascade (list #1 notify) |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`__thiscall` leaf** called from FX-host active cascade `FUN_004b8dc0` when walking list at host **`+0x1E0`** with **`(nodeObj, newFlag, param_3)`**.

Always stores:

```
*(char*)(this + 0x7f8) = param_2;   // enabled / active-ish byte
```

Then branches:

### Activate (`param_2 != 0`)

1. `*(float*)(this + 0x804) = 0.0` (`xorps` + `movss`)
2. `*(this + 0x810) = *(this + 0x8fc)`  (copy dword)
3. If **`(this+0x989) & 0x10`**: also `*(this + 0x808) = *(this + 0x900)` then return  
   Else return without the `+0x808` copy.

### Deactivate (`param_2 == 0`)

Only if **all** hold:

1. **`*(float*)(this + 0x900) >= DAT_00aaa66c`** where **`DAT_00aaa66c = 999999.0f`** (`read_memory` → `f0 23 74 49`)
2. **`*(*(this+4) + 0x28) != 4`** (type/class gate via object at `this+4`)
3. **`param_3 == 0`**
4. Intrusive list at **`this+0xa24`** non-empty (`node = *head; node != head`)

Then walk list: for each node, payload `node[2]`, zero:

```
*(payload + 0x16c) = 0
*(payload + 0x170) = 0
```

```c
void __thiscall FxNode_SetEnabledCascade_Inferred(void *this, char enabled, char param_3);
```

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005bbb90_FUN_005bbb90.md` | ≡ live |
| Annotated | `docs/reconstruction/raw/aa_005bbb90_FUN_005bbb90.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005bbb90.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_005bbb90.cpp` | Parent-seed only |
| Function record | `docs/reconstruction/functions/aa_005bbb90_FUN_005bbb90.md` | Scaffold |
| Live decompile | Ghidra @ `0x005bbb90` | **≡ raw** |
| Live `read_memory` | body + `DAT_00aaa66c` | CF + constant seal |
| Parent dual | `reviews/A_aa_004b8dc0_FUN_004b8dc0.md` | Forwards `param_3` here only |
| Callers | **1** xref: `FUN_004b8dc0` @ `0x004b8ded` | Host cascade |

**Not performed:** Launcher, runtime, bit-exact. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; 2 stack chars; `ret 8` | **High** | bytes `C2 08 00` |
| Store enable at **`this+0x7f8`** | **High** | first store |
| Activate: zero `+0x804`; copy `+0x8fc→+0x810` | **High** | |
| Activate optional: if `+0x989&0x10` copy `+0x900→+0x808` | **High** | |
| Deactivate gate: float `+0x900 >= 999999.0` | **High** | `DAT_00aaa66c` sealed |
| Deactivate gate: type `*(this+4)+0x28 != 4` | **High** | |
| Deactivate gate: `param_3 == 0` | **High** | |
| List walk `+0xa24`; clear payload `+0x16c/+0x170` | **High** | |
| Sole caller `FUN_004b8dc0` | **High** | |
| Product English / field names | **Tentative** | `_Inferred` |
| Meaning of 999999 sentinel (sentinel “unset” / max?) | **Probable** | common large-float sentinel |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| store `+0x7f8` | **Yes** |
| activate branch vs deactivate | **Yes** |
| activate field writes + bit10 gate | **Yes** |
| deactivate multi-gate + list zero | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void __thiscall FUN_005bbb90(int param_1, char param_2, char param_3)
{
  int iVar1;
  int *piVar2;

  *(char *)(param_1 + 0x7f8) = param_2;
  if (param_2 == '\0') {
    if ((((DAT_00aaa66c < *(float *)(param_1 + 0x900) || DAT_00aaa66c == *(float *)(param_1 + 0x900)
          ) && (*(int *)(*(int *)(param_1 + 4) + 0x28) != 4)) && (param_3 == '\0')) &&
       (piVar2 = (int *)**(int **)(param_1 + 0xa24), piVar2 != *(int **)(param_1 + 0xa24))) {
      do {
        iVar1 = piVar2[2];
        *(undefined4 *)(iVar1 + 0x16c) = 0;
        *(undefined4 *)(iVar1 + 0x170) = 0;
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0xa24));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x804) = 0;
    *(undefined4 *)(param_1 + 0x810) = *(undefined4 *)(param_1 + 0x8fc);
    if ((*(byte *)(param_1 + 0x989) & 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x808) = *(undefined4 *)(param_1 + 0x900);
      return;
    }
  }
  return;
}
```

### 4.2 Constants

| Address | LE bytes | float32 | Role |
|---|---|---:|---|
| `0x00aaa66c` | `f0 23 74 49` | **999999.0** | deactivate gate threshold (`+0x900 >=`) |

### 4.3 Layout (touched)

| Off | Role |
|---|---|
| `+0x7f8` | **enabled/active byte** (always written) |
| `+0x804` | float; cleared on activate |
| `+0x808` | dword/float; optional copy from `+0x900` when bit |
| `+0x810` | dword; copy from `+0x8fc` on activate |
| `+0x8fc` | source for `+0x810` |
| `+0x900` | float compared to 999999; also optional source for `+0x808` |
| `+0x989` | flags; **bit 4 (0x10)** gates `+0x808` copy |
| `+0x4` → `+0x28` | type/class int gate (`!= 4`) |
| `+0xa24` | intrusive list head (deactivate clear walk) |
| payload `+0x16c/+0x170` | zeroed pair |

---

## 5. Callers

| Call site | Function | Role |
|---|---|---|
| `0x004b8ded` | `FUN_004b8dc0` | Host cascade list `+0x1E0`; forwards **`param_3`** |

Weapon path note (parent): fire-start `(1,0)` / stop `(0,0)` — when `param_3==0`, deactivate list-clear can run under gates.

---

## 6. Gaps / open

1. Product type of this node and list payloads.
2. Semantic of floats at `+0x804/+0x808/+0x810/+0x900` (timer? scale? distance?).
3. Why type `==4` suppresses deactivate clear.
4. Runtime observation of 999999 sentinel use.
5. Clean still scaffold `FUN_*`.

**Verdict:** **accept-with-gaps** — dual **ABI + branch CF + constant 999999 + offsets + single-caller / param_3 role** sealed; product English open.
