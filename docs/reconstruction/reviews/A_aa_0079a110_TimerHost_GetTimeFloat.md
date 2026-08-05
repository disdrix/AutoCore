# Review A (reconstruction fidelity): `aa_0079a110` TimerHost_GetTimeFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079a110` |
| **VA** | `0x0079a110`–`0x0079a116` |
| **Canonical name** | `TimerHost_GetTimeFloat` |
| **Ghidra name** | `FUN_0079a110` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W21-I) |
| **Counterpart** | `reviews/B_aa_0079a110_TimerHost_GetTimeFloat.md` |
| **System** | timer-clock |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; 34 xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Return the **float** at **`host+0x238`** (ST0). Used widely as **current time / anim sample clock**, frequently with global host `DAT_00b04c74`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0079a110_FUN_0079a110.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0079a110_FUN_0079a110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TimerHost_GetTimeFloat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0079a110.cpp` |
| Function record | `docs/reconstruction/functions/aa_0079a110_FUN_0079a110.md` |
| Live | decompile ≡ raw; body `d98138020000c3` |

---

## 3. Signature (sealed)

```c
// ECX = host*
float TimerHost_GetTimeFloat(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ECX** | **High** |
| Return | ST0 from FLD dword | **High** |
| Side effects | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
return *(float *)(host + 0x238);
```

| Stage | Match | Conf |
|---|---|---|
| `FLD [ECX+0x238]` | **Yes** | **High** |
| Immediate `RET` | **Yes** | **High** |
| No callees | **Yes** | **High** |
| Body 7 B | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
d98138020000c3
```

Range **`0x0079a110`–`0x0079a116`**. Pad `CC` to next function.

---

## 6. Callers (context)

34 xrefs. Representative sealed by prior duals:

- `Object_LoadOrReplaceAnimSlot` — duration = this unit on `DAT_00b04c74`.
- `AnimHost_SelectBlendSlot` — sample time feed.
- `CVOGPlayerVehicle_UpdateTurretAiming` — time reads.

---

## 7. Confidence / gaps

| Claim | Conf |
|---|---|
| Field load CF | **High** |
| ECX host ABI | **High** |
| Time/duration usage | **High** (callers) |
| Product type/field name | **Open** |
| Units | **Open** |

**Verdict: accept** — trivial stub fully sealed; only product English/units open (non-blocking).
