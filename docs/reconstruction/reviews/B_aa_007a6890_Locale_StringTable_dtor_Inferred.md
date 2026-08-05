# Review B (skeptical / adversarial): `Locale_StringTable_dtor_Inferred` / `FUN_007a6890` @ `0x007a6890`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007a6890_Locale_StringTable_dtor_Inferred.md` |
| **Verdict** | **accept** — reject GetLocale identity, `delete this` inside body, stack-this confusion |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is GetLocale (`007a6880`) | **Falsified** — frees heap; leaf is 3-byte load |
| 2 | This is GetInstance | **Falsified** — no once-flag; always frees |
| 3 | `operator_delete(this)` inside | **Falsified** — only buffer frees; scalar dtor `00424810` owns object delete |
| 4 | Stack-this like ctor | **Falsified** — **ECX** (`mov ebx,ecx`); atexit sets ECX |
| 5 | Frees fewer/more than 10 rings | **Falsified** — counter **10** |
| 6 | Leaves dangling non-null ring slots | **Falsified** — explicit store 0 after free |
| 7 | Product name sealed | **Open** |
| 8 | Runtime atexit order verified | **Open** — static only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this ABI | **Confirmed** | Wrong object freed |
| 10 ring frees | **Confirmed** | Leak or double-free |
| Null after free | **Confirmed** | UAF if reused without ctor |
| No `delete this` | **Confirmed** | Double-free if port adds it **and** scalar dtor also deletes |
| Pair with ctor | **High** | Asymmetric free |
| Pack geometry names | **Medium** | Port may mis-index packs |
| Product name | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// thiscall ECX
void dtor(LocaleStringTable* self):
  self.vfptr = kVtable
  for i in 0..9:
    delete[] self.ringBuf[i]; self.ringBuf[i] = null
  for each of 5 pack groups:
    free up to packCount[g] pointers; null them

// atexit: ECX = &DAT_00d1f660; dtor()
// scalar deleting dtor may then operator_delete(self) if heap instance
```

---

## 4. Falsification notes

### 4.1 Address adjacency trap

`007a6880` (get code), `007a6890` (dtor), `007a6910` (ctor), `007a69d0` (get instance) are **siblings**. Off-by-name bugs are common; bytes diverge completely.

### 4.2 atexit thunk

GetInstance dual already sealed thunk → **this** dtor, not GetLocale. Do not “fix” thunk target to `6880`.

### 4.3 `operator_delete__` vs `operator_delete`

Body uses array delete for buffers (matches `operator_new__` in ctor). Ports that mix scalar delete on ring buffers may fault under some CRT configurations.

---

## 5. Open questions

1. Product name.
2. Exact pack pointer matrix field map.
3. Whether all 5 groups are always language packs vs mixed resources.

**Verdict:** **accept**. Sealed free CF and ECX ABI. Reject GetLocale/GetInstance conflation and in-body `delete this`.
