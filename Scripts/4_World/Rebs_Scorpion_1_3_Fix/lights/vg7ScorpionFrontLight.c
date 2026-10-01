// Retro 80s halogen / yellow headlight for the Scorpion
// Warmer, more yellow tone than modern white HID
class vg7ScorpionFrontLight extends CarLightBase
{
	void vg7ScorpionFrontLight()
	{
		// Segregated (single bulb) – classic warm halogen
		m_SegregatedBrightness = 5.5;
		m_SegregatedRadius = 58;
		m_SegregatedAngle = 105;
		m_SegregatedColorRGB = Vector(1.0, 0.82, 0.45);		// strong yellow-amber

		// Aggregated (both / brighter)
		m_AggregatedBrightness = 11;
		m_AggregatedRadius = 78;
		m_AggregatedAngle = 115;
		m_AggregatedColorRGB = Vector(1.0, 0.85, 0.50);		// slightly brighter warm yellow

		FadeIn(0.25);
		SetFadeOutTime(0.2);

		SegregateLight();
	}
};
