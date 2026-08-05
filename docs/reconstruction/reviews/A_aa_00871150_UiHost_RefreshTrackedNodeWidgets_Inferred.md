# Review A (reconstruction fidelity): `aa_00871150` UiHost_RefreshTrackedNodeWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00871150` |
| **VA** | `0x00871150` |
| **Canonical name** | `UiHost_RefreshTrackedNodeWidgets_Inferred` |
| **Ghidra name** | `FUN_00871150` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W21-S) |
| **Counterpart** | `reviews/B_aa_00871150_UiHost_RefreshTrackedNodeWidgets_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Large **UI host → multi-widget rebind** helper driven by a tracked list node:

```c
// ABI: host in EAX; node on stack; ret 4
void UiHost_RefreshTrackedNodeWidgets(UiHost* host, TrackedNode* node) {
  if (!host->vtbl_IsVisible(+0x3d8)) return;
  if (!node) return;

  FUN_007fd970(format_from(node+0x1c));  // CL = *(u8*)(node+0x1c) - 0x0f

  idA = node[+8]; idB = node[+0xc];

  // For each non-null widget pointer on host:
  //   +0x5e8 [0x17a]  "%d"          vtbl 45c/460/464/34c
  //   +0x5ec [0x17b]  flag-1 path   vtbl 45c/464/34c
  //   +0x5f0 [0x17c]  "%d/%s/%s"    + FUN_0051fa10 / 0051f910
  //   +0x5f4 [0x17d]  gated by host+0x50c vs short(node+0x1c)
  //   +0x600 [0x180]  + FUN_008705c0
  //   +0x5fc [0x17f]  "%d/%d"       + -*(u16*)(node+0x14)
  //   +0x5f8 [0x17e]  "%d"

  if (DAT_00d1b6d8 selected pair == (idA,idB))
    re-call vtbl+0x464 on each non-null widget;  // highlight
}
```

Primary sealed caller context: `FUN_008718a0` clears `*node` then calls this with host in EAX.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00871150_*`, `UiHost_RefreshTrackedNodeWidgets_Inferred.cpp` |
| Function record | `functions/aa_00871150_FUN_00871150.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00871150` (2026-07-29) |
| Bytes | `read_memory` prologue 64 B + epilogue near `0x008715ea` |
| Callers | 4 live: `00871600`, `008718a0`, `008718d0`, `008719d0` |
| Sibling | `UiHost_ClearTrackedPairAndRefresh` (`0x008718a0`) already dual-sealed |

### ABI bytes (sealed)

```
00871150  81EC08010000      sub  esp, 0x108
00871156  55                push ebp
00871157  8BAC2410010000    mov  ebp, [esp+0x110]  ; node
0087115e  56                push esi
0087115f  8BF0              mov  esi, eax          ; host
00871161  8B06              mov  eax, [esi]
00871163  8BCE              mov  ecx, esi
00871165  FF90D8030000      call [eax+0x3d8]       ; visible?
...
          81C408010000      add  esp, 0x108
          C20400            ret  4
```

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX host + stack node + ret 4 | **Confirmed** | prologue + epilogue |
| Visible gate + null node early out | **Confirmed** | decomp ≡ bytes |
| Widget bank +0x5e8..+0x600 | **Confirmed** | dword indices 0x17a..0x180 |
| Node id pair +8/+0xc | **Confirmed** | matches 00871690/008718a0 |
| FUN_007fd970 after CL=node+0x1c-0x0f | **Confirmed** | bytes (decomp under-reports CL) |
| Selection rebind via DAT_00d1b6d8 | **High** | decomp |
| Role name `_Inferred` | **High** | caller + multi-widget bind |
| Product widget English | **Open** | |
| Full vtbl 45c/460/464 arg packs | **Tentative** | decomp lossy |
| clean ≡ raw ≡ live CF | **Confirmed** | gates + bank + select |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Visible + null gates | **Yes** |
| Format prep FUN_007fd970 | **Yes** (bytes refine CL) |
| Seven optional widget arms | **Yes** |
| 0x17d host+0x50c gate | **Yes** |
| DAT_00d1b6d8 pair match rebind | **Yes** |
| ret 4 | **Yes** |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_008718a0` | clear tracked pair then refresh |
| Caller | `FUN_00871600` / `008718d0` / `008719d0` | other host paths |
| Callee | `FUN_007fd970` | format prep |
| Callee | `FUN_0051fa10` / `FUN_0051f910` | string pair for 0x17c |
| Callee | `FUN_008705c0` | prep for 0x180 |
| Callee | `sprintf` | label formats |

---

## 6. Gaps / open

1. Product English names for host class and each widget slot.
2. Exact stack args to widget vtbl 0x45c/460/464/34c (decomp residual).
3. Nested dual of `FUN_007fd970`, `FUN_008705c0`, `FUN_0051fa10`, `FUN_0051f910`.
4. Distinct text content on 0x17d branches (decomp shows same SetText call shape).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — ABI + widget bank + node id pair + selection rebind sealed; product English and full vtbl packs residual.
