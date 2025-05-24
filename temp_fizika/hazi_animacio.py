import manim as m


class Homework(m.Scene):
    def mwait(self, m=1):
        self.wait(m * 0.1)

    def mplay(self, *args, **kwargs):
        self.play(*args, **kwargs, run_time=0.5)

    def construct(self):
        s = "Egy fizika házi feladat"
        txt0 = m.Text(s, font_size=48)
        # s = "Házi feladat"
        txt1 = m.Text(s, font_size=24).shift(m.UP * 3.5)

        # plane = m.NumberPlane(
        #     background_line_style=dict(
        #         stroke_color=m.DARK_GRAY,
        #         stroke_width=2,
        #         stroke_opacity=1
        #     )
        # )
        # self.add(plane)

        self.mplay(m.Write(txt0))
        self.mplay(m.Transform(txt0, txt1))

        dot = m.Circle(0.6, m.WHITE)
        self.mplay(m.GrowFromCenter(dot))

        arrow1 = m.Arrow((0, 0, 0), m.DOWN * 3, buff=0, color=m.RED)
        arrow2 = m.Arrow((0, 0, 0), m.DOWN * 3, buff=0, color=m.BLUE)
        self.mplay(m.GrowArrow(arrow2), m.GrowArrow(arrow1))
        arrow1_text = m.MathTex(r"\vec{F}_{neh}").next_to(arrow1)
        self.mplay(m.Write(arrow1_text))

        arrow2_1 = m.Arrow((0, 0, 0), m.UP * 3, buff=0, color=m.BLUE)
        self.mplay(m.Transform(arrow2, arrow2_1, path_arc=-m.PI))
        arrow2_text = m.MathTex(r"\vec{F}_{e}").next_to(arrow2)
        self.mplay(m.Write(arrow2_text))

        self.mwait()
        # self.play(
        #     m.Write(arrow1_text),
        #     m.Write(arrow2_text),
        # )

        eqs = [
            (r"\vec{F}_{neh}", "=", r"-\vec{F}_{e}"),
            (r"|\vec{F}_{neh}|", "=", r"|\vec{F}_{e}|"),
            (r"F_{neh}", "=", r"{F}_{e}"),
            (r"m \cdot g", "=", r"E \cdot Q"),
            (r"m", "=", r"E \cdot Q \mathbin{/} g"),
            (
                "m",
                "=",
                # r"10^5 \cdot 3.2 \cdot 10^{-17} \mathbin{/} 10"
                r"\frac{10^5 \cdot 3.2 \cdot 10^{-17}}{10}",
            ),
            (r"m", "=", r"3.2 \cdot 10^{-13} kg"),
        ]

        eqs = [
            # m.MathTex(*eq).to_edge(m.RIGHT)
            m.MathTex(*eq).shift(self.camera.frame_width / 4 * m.RIGHT)
            for eq in eqs
        ]
        eq1, eq2, eq3, eq4, eq5, eq6, eq7 = eqs

        def animate_eq(a, b, f=-m.PI / 2):
            self.mplay(m.TransformMatchingShapes(a, b, path_arc=f))
            self.mwait()

        animate_eq(m.Group(arrow1_text, arrow2_text), eq1)
        animate_eq(eq1, eq2)
        animate_eq(eq2, eq3)
        animate_eq(eq3, eq4)
        animate_eq(eq4, eq5)

        rows = (
            m.VGroup(
                m.MathTex("E = 10^5 N/C"),
                m.MathTex(r"Q = 3.2 \cdot 10^{-17} C"),
                m.MathTex("m", "=", r"\textbf{?}"),
            )
            .arrange(m.DOWN, buff=0.4, aligned_edge=m.LEFT)
            .shift(m.LEFT * 4)
        )

        self.mplay(m.Write(rows))
        self.mwait()

        animate_eq(eq5, eq6)
        animate_eq(eq6, eq7)

        framebox = m.SurroundingRectangle(eq7)
        self.mplay(m.Create(framebox))
        self.mwait(2)
